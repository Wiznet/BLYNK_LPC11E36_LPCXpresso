# Simple Blynk Client for W5500-EVB

<!-- W5500 EVB pic -->
<p align="center">
  <img width="50%" src="http://wizwiki.net/wiki/lib/exe/fetch.php?media=products:w5500:w5500_evb:w5500-evb_side.png" />
</p>

## What is 'Blynk'?
### Blynk - build an app for your Arduino project in 5 minutes
Imagine a prototyping board on your smartphone where you drag and drop buttons, sliders, displays, graphs and other functional widgets. And in a matter of minutes these widgets can control Arduino and get data from it.

For more details, please refer to the Blynk official websiet, http://www.blynk.cc/

## How to Use
The Simple Blynk Client for W5500-EVB is roughly composed of the following functions.
- blynk_begin() : Handler the HTTP server initialization (Server IP and Port, Auth key, Buf and Socket number)
- blynk_run() : Simple Blynk Client process handler in main routine.

Step 1. Download Blynk App and Get the Auth key Token in the App (Apple App Store / Google play)
 - Apple App Store: https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8
 - Google play: https://play.google.com/store/apps/details?id=cc.blynk

Step 2. Install Simple Blynk Client Library to W5500-EVB

Step 3. Set your App's Auth key in the code (Auth[] in main.c)

Step 4. Build the Project and program to W5500-EVB

Step 5. Run!

!! Notice !!

You have to use this example with (1) DHCP client code and Router(DHCP server) or (2) Public IP address.
