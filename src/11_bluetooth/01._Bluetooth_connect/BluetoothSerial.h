/******************************************************************************************
 * FileName     : BluetoothSerial.h
 * Description  : BLE 통신
 * Author       : 이 현
 * Created Date : 2024.07.18
 * Reference    : 
 * Modified     : 2024.07.18 : LH : BLE 통신방식 개선
 * Modified     : 2024.07.22 : LH : BLE 코드클린징
 ******************************************************************************************/

#ifndef BLUETOOTHSERIAL_H
#define BLUETOOTHSERIAL_H

// 아두이노 라이브러리 포함
#include <Arduino.h>
// BLE 디바이스 관련 라이브러리 포함
#include <BLEDevice.h>
// BLE 서버 관련 라이브러리 포함
#include <BLEServer.h>
// BLE 유틸리티 관련 라이브러리 포함
#include <BLEUtils.h>
// BLE2902 관련 라이브러리 포함
#include <BLE2902.h>

// UART 서비스 UUID 정의
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" 
// RX 특성 UUID 정의
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" 
// TX 특성 UUID 정의
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" 

class BluetoothSerial {
public:
    BluetoothSerial(const char* name = nullptr);                     // 생성자
    void begin();                                                    // BLE 초기화 메서드
    void on_received(void (*callback)(const String&));               // 수신 콜백 설정 메서드
    void send(const String& value);                                  // 데이터 전송 메서드
    bool isConnected();                                              // 연결 상태 확인 메서드
    String _ble_name;                                                // BLE 장치 이름 (public으로 변경)

private:
    BLEServer* pServer;                                              // BLE 서버 포인터
    BLEService* pService;                                            // BLE 서비스 포인터
    BLECharacteristic* pCharacteristicRX;                            // RX 특성 포인터
    BLECharacteristic* pCharacteristicTX;                            // TX 특성 포인터
    bool deviceConnected;                                            // 연결 상태 저장 변수
    void (*onReceiveCallback)(const String&);                        // 수신 콜백 함수 포인터

    String make_ble_name();                                          // BLE 이름 생성 메서드
    void handle_send(const String& value);                           // 송신 데이터 처리 함수

    friend class MyServerCallbacks;
    friend class MyCallbacks;
};

// BLE 서버 콜백 클래스 정의
class MyServerCallbacks: public BLEServerCallbacks {
    BluetoothSerial* serial;                                         // BluetoothSerial 객체 포인터
public:
    MyServerCallbacks(BluetoothSerial* serial) : serial(serial) {}
    void onConnect(BLEServer* pServer) override {
        Serial.println("연결에 성공했습니다!");                          // 클라이언트 연결 메시지 출력
        serial->deviceConnected = true;                              // 연결 상태를 true로 설정
    }

    void onDisconnect(BLEServer* pServer) override {
        Serial.println("연결이 끊겼습니다.");                       // 클라이언트 연결 해제 메시지 출력
        serial->deviceConnected = false;                             // 연결 상태를 false로 설정
    }
};

#endif // BLUETOOTHSERIAL_H
