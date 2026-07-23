#include "pxt.h"
#include "MicroBit.h"

namespace customBLE {

    // Target UUID: 0000bbbb-1234-5678-1234-56789abcdef0
    // Byte sequence reversed for Little-Endian BLE specification:
    // [0x00, 0x00, 0xbb, 0xbb, 0x12, 0x34, 0x56, 0x78, 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0] -> reversed
    const uint8_t CUSTOM_UUID_BYTES[] = {
        0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
        0x78, 0x56, 0x34, 0x12, 0xbb, 0xbb, 0x00, 0x00
    };

    //%
    void startCustomAdvertiser() {
        #if CONFIG_ENABLED(DEVICE_BLE)
        if (uBit.ble == NULL) {
            uBit.init();
        }

        // Stop default advertising payload
        uBit.bleManager.stopAdvertising();

        // Build Advertising Data Payload (AD Structure)
        // [0..2]  Flags: General Discoverable, BR/EDR Not Supported
        // [3..4]  Length (17 bytes: 1 byte type + 16 bytes UUID) & Type (0x07 = Complete 128-bit UUID list)
        // [5..20] 16-byte Little-Endian UUID payload
        uint8_t advData[] = {
            0x02, 0x01, 0x06, 
            0x11, 0x07,       
            0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
            0x78, 0x56, 0x34, 0x12, 0xbb, 0xbb, 0x00, 0x00
        };

        // Apply custom advertising payload and resume advertising
        uBit.bleManager.setAdvertisingData(advData, sizeof(advData));
        uBit.bleManager.startAdvertising();
        #endif
    }
}
