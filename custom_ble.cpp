#include "pxt.h"

namespace customBLE {

    //%
    void startCustomAdvertiser() {
#if CONFIG_ENABLED(DEVICE_BLE)
        // Ensure uBit is initialized
        if (!uBit.ble) {
            uBit.init();
        }

        // Access BLE manager via the 'ble' pointer
        if (uBit.ble) {
            uBit.ble->stopAdvertising();

            // Target UUID: 0000bbbb-1234-5678-1234-56789abcdef0 (Little-Endian)
            uint8_t advData[] = {
                0x02, 0x01, 0x06, 
                0x11, 0x07,       
                0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
                0x78, 0x56, 0x34, 0x12, 0xbb, 0xbb, 0x00, 0x00
            };

            uBit.ble->setAdvertisingData(advData, sizeof(advData));
            uBit.ble->startAdvertising();
        }
#endif
    }
}
