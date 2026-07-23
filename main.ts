//% color="#007ACC" weight=100 icon="\uf293" block="Custom BLE"
namespace customBLE {
    /**
     * Starts BLE advertising with the configured custom UUID.
     */
    //% block="start custom BLE UUID advertiser"
    //% shim=customBLE::startCustomAdvertiser
    export function startCustomAdvertiser(): void {
        // Fallback execution for the web simulator
        console.log("BLE custom advertiser initialized on simulator.");
    }
}
