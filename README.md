# ESP-IRMP_IRSND - Infared Multi Protocol Decoder and Encoder for ESP-IDF
Support up to 50 different protocols. </br>
This is a port version of the library IRMP & IRSND V3.2.6 on ESP-IDF framework.

# Features
- Extensive Protocol Support: support 50 different infrared (IR) and 3 radio frequency (RF) protocols.
- Concurrent Decoding: concurrently receive up to 40 IR protocols.
- Low Memory Footprint.
- Bidirectional Communication: support both receiving and sending of IR signals within the same application.

# Install
- Clone this repo and put in the component folder of your ESP-IDF project.
- Configure the irmpconfig.h and irsndconfig.h to enable/disable the protocols and other options. Please read the original documents below to understand the configurations and API calls.

# Documentation
### English
   http://www.mikrocontroller.net/articles/IRMP_-_english<br/>
   http://www.mikrocontroller.net/articles/IRSND_-_english
### German
   http://www.mikrocontroller.net/articles/IRMP<br/>
   http://www.mikrocontroller.net/articles/IRSND

# Example
### SimpleReceiver
Decode and log all incomming IR signal. The IR input pin is set at GPIO13, you can change it by changing the IRMP_BIT_NUMBER define line of the ESP_PLATFORM preprocessor definition in irmpconfig.h.
### SimpleSender
Send NEC frame every 1s. The IR output pin is set at GPIO4, you can change it by changing the IRSND_PIN define line of the ESP_PLATFORM preprocessor definition in irsndconfig.h.
