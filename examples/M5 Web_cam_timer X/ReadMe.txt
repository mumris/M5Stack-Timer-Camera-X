This software version is tested on M5 Timer Camera X  and provided "as is" by Saulius Pakalnis (Mumris).
New features added M5 Timer Camera X (ESP32, sensor OV3660). Compile the sources files with Arduino IDE (https://www.arduino.cc/). 

Arduino IDE setup->File->Preferences->Additional Boards Manager URLs:
https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
https://dl.espressif.com/dl/package_esp32_index.json

Arduino IDE setup->Board:"M5Stack-Timer-CAM"

For serial port programming, I recommend free software Termite.exe (https://termite.software.informer.com/3.2/)
1.	WIFI name and password is set or modified through Serial port connection during M5 Timer Camera X first run time (30 seconds timeout). They becomes default (saved in Nonvolatile memory).
2.	 Added simple security feature. Web password must be set during first run time (30 seconds timeout). It is saved in Nonvolatile memory. Then on LAN (Ethernet) Timer Camera X page can be accessed http://192.168.x.x:80/password
3.	Added feature for web access through Internet connection. Two ports (80, 81) must be forwarded in setup of local router. For an example, web access default port 80 to 5001, and live video streaming local port 81 to port 5002.
You can choose any not used port, just live streaming port number must be incremented by 1.  From internet it is accessed using http string, as http://x.x.x.x:5000/password, or using free DDNS service (for an example: www.duckdns.org) http://youraccountname.duckdns.org:5000/password,
Where “password” is your string, which you entered during first run of M5 Timer Camera X.
4.	Added watchdog feature which restarts ESP32 if free RTOS for some reasons halts. For stability reasons. The camera X restarts at every 14 hours if nobody streams live video.
5.	Memory is initiated to Max video frame size at start up. It gives dynamic memory allocation stability. 
6.	Face recognition is disabled for smallest frame size, as it “hangs” camera.
7.	On Camera WEB site added favicon, spinning windmill vertical axes rotor Tulip icon (just for a fun), RSSI (WIFI signal strength), frame rate and battery status indicators.
8.	Web HTML page is no more G-zipped as it is automatically modified when Web password is set. 
9.	Most companies have policy to filter all traffic coming to Internet. For this task, they target Google Chrome, Internet explorer, Microsoft Eadge or Firefox streams through their proxy servers. To avoid your home camera live video stream blocking I recommend Epic Privacy Browser (https://www.epicbrowser.com/).
