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

### Caution
You have to use this example with (1) DHCP client code and Router(DHCP server) or (2) Public IP address.

### Related Project GitHub Repositories
- [W5500-EVB Main](https://github.com/Wiznet/W5500_EVB)
- [Loopback Test](https://github.com/Wiznet/Loopback_LPC11E36_LPCXpresso): Loopback test example project (TCP server / TCP client / UDP)
- [HTTP Server](https://github.com/Wiznet/HTTPServer_LPC11E36_LPCXpresso): Web server example project
- [FTP Server](https://github.com/Wiznet/FTP_LPC11E36_LPCXpresso): FTP server example project
- [SNMPv1 Agent](https://github.com/Wiznet/SNMP_LPC11E36_LPCXpresso): SNMPv1 agent example project (Get/Set/Trap)
- [SNTP Client](https://github.com/Wiznet/SNTP_LPC11E36_LPCXpresso): NTP client example project
- [TFTP Client](https://github.com/Wiznet/TFTP_LPC11E36_LPCXpresso): TFTP client example project

## How to add a submodule of ioLibrary in project
- $ git submodule add git@github.com:Wiznet/ioLibrary_Driver.git project_src/ioLibrary
- $ git commit -m "description"
- $ git push

## How to clone a submodule of ioLibrary
- $ git clone git@github.com:Wiznet/HTTPServer_LPC11E36_LPCXpresso.git
- $ git submodule init
- $ git submodule update

## Revision History
Last release : May. 2015


