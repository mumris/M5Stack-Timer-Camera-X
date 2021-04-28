#include <cstring>
#include "esp_camera.h"
#include "battery.h"
#include <WiFi.h>
#include "camera_pins.h"
#include "index.h" 
#include "find_and_replace_string_in_HTML.h"
#include <EEPROM.h>
#include "esp_http_server.h"
#include "save_to_EEPROM.h"
#include <esp_task_wdt.h>
//3 seconds WDT
#define WDT_TIMEOUT 5
#define EEPROM_SIZE 1000 // this is maximum size
//#define MAXCOUNT 100
const char* ssid = "";
const char* password = "";
extern MyObject aaa, bbb, ccc;

extern bool streaming;
extern long rssi;
extern uint32_t avg_frame_time;
void startCameraServer();
extern httpd_handle_t camera_httpd;
extern httpd_handle_t stream_httpd;
httpd_uri_t stream_uri;
int not_streaming_count;
WiFiClient client1;
void setup() 
{
  
  avg_frame_time = 0;
  streaming = false;   
  Serial.begin(115200); 
  Serial.setDebugOutput(true);
  Serial.println();
  Serial.setTimeout(30000); // set timeout of 30 seconds
  EEPROM.begin(EEPROM_SIZE);
  delay(500); 
  
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_QXGA;  //FRAMESIZE_QVGA;  //FRAMESIZE_XGA;
  config.jpeg_quality = 4;
  config.fb_count = 2;
 
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  //initial sensors are flipped vertically and colors are a bit saturated
  s->set_vflip(s, 1);//flip it back
  s->set_brightness(s, 1);//up the blightness just a bit
  s->set_saturation(s, -2);//lower the saturation
  s->set_gainceiling(s, (gainceiling_t)511); 
  s->set_exposure_ctrl(s, -1);
  //drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_QVGA);

delay(15000);
Serial.println("WIFI and WEB page configuration. If you didn't set WIFI password, do it now. ");
delay(1000); 
EEPROM_setup();  
show_EEPROM_setup();
replace_multiple_str(index_html0, input, pattern, aaa.a, output);
WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE);
WiFi.setHostname("M5_Timer_X-CAM"); // set hostname  
WiFi.setTxPower(WIFI_POWER_19_5dBm); //set Maximum transmit power (150mA)
delay(1000);
WiFi.begin(bbb.a, ccc.a);   //WiFi.begin(ssid, password);    
Serial.println("Connecting to WIFI");  
  ///////////// 
  int status_counter = 30; // WIFI attempt of 30 seconds 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
    status_counter--;
    if (status_counter <=0) 
    {
        Serial.println("WIFI connection failed. Now stand by for 1 hour. Then camera controller will restart. ");
        status_counter = 3600; // Make delay of 1 hour before a new attempt to connect to WIFI
        while (status_counter >0)
        {        
        Serial.println(status_counter);
        status_counter--;
        delay(1000);
        }
    ESP.restart();   
    }
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();
  Serial.print("Use    http://");
  Serial.print(WiFi.localIP());
  Serial.print("/");
  Serial.print(aaa.a);
  Serial.println("   to connect");
  if (!esp_camera_sensor_get()) Serial.println("Camera is OFF");   
  if (camera_httpd) 
  {                         
    Serial.println("httpd server is ON");           // print a message out in the serial port
  }
  else Serial.println("httpd server is OFF");
  streaming = false;
  not_streaming_count = 100000; //restart ESP more than every if non streaming
  esp_task_wdt_init(WDT_TIMEOUT, true); //enable panic so ESP32 restarts
  esp_task_wdt_add(NULL); //add current thread to WDT watch
  bat_init(); // will hold bat output
}

void loop() 
{
 int64_t time1;
 int loopcount;
 
//Serial.println("Signaling OK to WDT...");
esp_task_wdt_reset();

 // put your main code here, to run repeatedly:
 if (WiFi.status() == WL_CONNECTED)
 {
  // print the received signal strength when streaming:
  rssi = WiFi.RSSI();
  loopcount = 120; 
  if (esp_camera_sensor_get())                // If a new client connects
  {                             
    //Serial.println("Camera is ON");         // print a message out in the serial port   
    //Serial.println(clientIP);
      int64_t time2 = esp_timer_get_time();
      if (time1 == time2)  {bat_disable_output(); ESP.restart();}
      else time1 = time2;    
  if (streaming == true) not_streaming_count = 100000;
  else not_streaming_count--;
  if (not_streaming_count <= 0)  {bat_disable_output(); ESP.restart();}
  Serial.println(not_streaming_count);
  //Serial.printf("  Battery: %.3f V\r\n", bat_get_voltage()/1000.0); 
  }
    else Serial.println("Camera is OFF");   
}
 else
 {
  loopcount--;
  Serial.print("WIFI signal lost, ESP will restart after: ");
  Serial.println(loopcount);
  if (loopcount <=0)  {bat_disable_output(); ESP.restart();}
 }
  delay(500);
}
