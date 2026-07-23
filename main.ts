// Define your custom service UUID
#define BT_UUID_CUSTOM_SERVICE_VAL  BT_UUID_128_ENCODE(1, 2, 3, 4, (uint64_t)0)
static struct bt_uuid_128 my_service_uuid = BT_UUID_INIT_128(BT_UUID_CUSTOM_SERVICE_VAL);

// Define the service
BT_GATT_SERVICE_DEFINE(my_service_svc,
    BT_GATT_PRIMARY_SERVICE(& my_service_uuid),
    BT_GATT_CHAR1
);