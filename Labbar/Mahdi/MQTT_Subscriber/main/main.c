#include "secret.h" //make your own secretfile
#include <stdio.h>
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "mqtt_client.h"

// Wi-Fi credentials
#define myssid WIFI_SSID
#define mypass WIFI_PASS

#define MyTopic "arduino/echo"
// #define MyTopic "your toppic"
//  #define MyBroker "your brocker address"
#define MyBroker "mqtt://test.mosquitto.org"

// --------------------
// Wi-Fi connection
// --------------------
void wifi_connection()
{
    // Initialize NVS (Non-Volatile Storage)
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize TCP/IP stack
    ESP_ERROR_CHECK(esp_netif_init());

    // Create default event loop
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // Create default Wi-Fi station
    esp_netif_create_default_wifi_sta();

    // Initialize Wi-Fi driver
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    // Set Wi-Fi to station mode
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    // Configure SSID and password
    wifi_config_t wifi_cfg = {
        .sta = {
            .ssid = myssid,
            .password = mypass,
        },
    };
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_cfg));

    // Start Wi-Fi
    ESP_ERROR_CHECK(esp_wifi_start());

    // Connect to Wi-Fi
    ESP_ERROR_CHECK(esp_wifi_connect());

    // Wait for connection
    int wifi_timeout = 0;
    while (1)
    {
        wifi_ap_record_t ap_info;
        if (esp_wifi_sta_get_ap_info(&ap_info) == ESP_OK)
        {
            printf("Wi-Fi CONNECTED! RSSI: %d dBm\n", ap_info.rssi);
            break;
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS);
        wifi_timeout++;

        if (wifi_timeout > 15)
        { // Timeout after 15 seconds
            printf("Wi-Fi timeout - could not connect\n");
            return;
        }
    }
}

// --------------------
// MQTT event handler
// --------------------
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    // Convert generic event to MQTT event
    esp_mqtt_event_handle_t event = event_data;

    switch (event->event_id)
    {
    case MQTT_EVENT_CONNECTED:
        printf("MQTT CONNECTED!\n");
        // Subscribe to topic after connecting
        esp_mqtt_client_subscribe(event->client, MyTopic, 0);
        break;

    case MQTT_EVENT_DATA:
        // Print received topic and payload
        printf("Topic: %.*s\n", event->topic_len, event->topic);
        printf("Payload: %.*s\n", event->data_len, event->data);
        break;

    default:
        break;
    }
}

// --------------------
// MQTT Subscriber setup if you want local brocker
// --------------------

// void MqttSubscriber() {
//     esp_mqtt_client_config_t mqtt_cfg = {
//         .broker.address.uri = MyBroker,
//         .credentials = {
//             .username = "your username",
//             .authentication.password = "your pass"  // Samma som du skapade
//         }
//     };

//     esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
//     esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
//     esp_mqtt_client_start(client);
// }

// if you want a webbrocker like mqtt://test.mosquitto.org
void MqttSubscriber()
{
    // Init default MQTT config (empty)
    esp_mqtt_client_config_t mqtt_cfg = {0};

    // Init client
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);

    // Set broker URI manually
    esp_mqtt_client_set_uri(client, MyBroker);

    // Register event handler
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);

    // Start MQTT
    esp_mqtt_client_start(client);
}
// --------------------
// Main application
// --------------------
void app_main(void)
{
    printf("Starting Wi-Fi connection...\n");
    wifi_connection();
    printf("Wi-Fi connected, starting MQTT subscriber...\n");
    MqttSubscriber();
}
