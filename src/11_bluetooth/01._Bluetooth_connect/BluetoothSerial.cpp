/******************************************************************************************
 * FileName     : BluetoothSerial.cpp
 * Description  : BLE 통신
 * Author       : 이 현
 * Created Date : 2024.07.18
 * Reference    : 
 * Modified     : 2024.07.18 : L H : BLE 통신방식 개선
 * Modified     : 2024.07.22 : L H : BLE 코드클린징
 * Modified     : 2024.07.31 : SCS : BLE 이름 생성 메서드 수정
 ******************************************************************************************/

#include "BluetoothSerial.h"       // BluetoothSerial 헤더 포함
#include <esp_bt_device.h>         // ESP32 BLE 디바이스 관련 라이브러리 포함
#include <esp_system.h>

// BLE 특성 콜백 클래스 정의
class MyCallbacks: public BLECharacteristicCallbacks {
    BluetoothSerial* serial;       // BluetoothSerial 객체 포인터
public:
    MyCallbacks(BluetoothSerial* serial) : serial(serial) {}
    void onWrite(BLECharacteristic *pCharacteristic) override {
        std::string value = pCharacteristic->getValue(); // 특성 값 읽기
        if (value.length() > 0) {
            String receivedValue;
            for (char c : value) {          // 수신된 값을 String 객체로 변환
                receivedValue += c;
            }
            receivedValue.trim();           // 불필요한 공백 제거
            if (serial->onReceiveCallback) { // 콜백 함수가 설정되어 있는지 확인
                serial->onReceiveCallback(receivedValue); // 콜백 함수 호출
            }
        }
    }
};

// BluetoothSerial 생성자
BluetoothSerial::BluetoothSerial(const char* name)
    : pServer(nullptr), pService(nullptr),
      pCharacteristicRX(nullptr), pCharacteristicTX(nullptr),
      onReceiveCallback(nullptr), deviceConnected(false) {
    if (name == nullptr || strlen(name) <= 0) {// 2024.07.31 : SCS : 조건 추가
        _ble_name = make_ble_name();           // BLE 이름 생성
    } else {
        _ble_name = String(name);              // 사용자 지정 이름 사용
    }
}

// BluetoothSerial 초기화 메서드
void BluetoothSerial::begin() {
    Serial.begin(115200);                    // 시리얼 통신 시작
    while (!Serial);

    BLEDevice::init(_ble_name.c_str());        // BLE 디바이스 초기화
    pServer = BLEDevice::createServer();                            // BLE 서버 생성
    pServer->setCallbacks(new MyServerCallbacks(this));

    pService = pServer->createService(BLEUUID(SERVICE_UUID));          // BLE 서비스 생성

    pCharacteristicRX = pService->createCharacteristic(
                          BLEUUID(CHARACTERISTIC_UUID_RX),
                          BLECharacteristic::PROPERTY_WRITE // RX 특성 생성
                        );
    pCharacteristicRX->setCallbacks(new MyCallbacks(this)); // RX 콜백 설정

    pCharacteristicTX = pService->createCharacteristic(
                          BLEUUID(CHARACTERISTIC_UUID_TX),
                          BLECharacteristic::PROPERTY_NOTIFY // TX 특성 생성
                        );

    BLE2902* p2902Descriptor = new BLE2902(); // BLE2902 디스크립터 생성
    pCharacteristicTX->addDescriptor(p2902Descriptor); // TX 특성에 디스크립터 추가

    pService->start(); // BLE 서비스 시작

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising(); // BLE 광고 시작
    pAdvertising->addServiceUUID(BLEUUID(SERVICE_UUID)); // 광고에 서비스 UUID 추가
    pAdvertising->start(); // 광고 시작

    Serial.print("Bluetooth device active, name: "); // BLE 활성화 메시지 출력
    Serial.println(_ble_name); // BLE 이름 출력
}

// BLE 이름 생성 메서드
String BluetoothSerial::make_ble_name() {
    /*
    const uint8_t* mac = esp_bt_dev_get_address(); // BLE MAC 주소 가져오기
    if (mac == nullptr) {
        return "UNKNOWN"; // MAC 주소가 없으면 "UNKNOWN" 반환
    }
    return String("E_") + String(mac[3], HEX) + String(mac[4], HEX) + String(mac[5], HEX); // MAC 주소를 기반으로 이름 생성
    */

    // 2024.07.30 : SCS
    // BLE 이름 생성 메서드 
    uint8_t baseMac[6];
    char baseMacChr[18] = {0};
    esp_read_mac(baseMac, ESP_MAC_BT);
    sprintf(baseMacChr, "E_%02X:%02X:%02X", baseMac[3], baseMac[4], baseMac[5]);
    return String(baseMacChr);
}

// 수신 콜백 설정 메서드
void BluetoothSerial::on_received(void (*callback)(const String&)) {
    onReceiveCallback = callback; // 수신 콜백 함수 설정
}

// 데이터 전송 메서드
void BluetoothSerial::send(const String& value) {
    if (value.length() == 0) return; // 빈 문자열 전송 방지
    handle_send(value); // 데이터 송신 처리
}

// 송신 데이터 처리 함수
void BluetoothSerial::handle_send(const String& value) {
    String trimmedValue = value;
    trimmedValue.trim(); // 불필요한 공백 제거
    if (pCharacteristicTX != nullptr) { // TX 특성이 유효한지 확인
        pCharacteristicTX->setValue(trimmedValue.c_str()); // TX 특성에 값 설정
        pCharacteristicTX->notify(); // 클라이언트에게 알림
        Serial.print("Sent: "); // 송신 메시지 출력
        Serial.println(trimmedValue); // 송신된 값 출력
    }
}

// 연결 상태 확인 메서드
bool BluetoothSerial::isConnected() {
    return deviceConnected; // 연결 상태 반환
}
