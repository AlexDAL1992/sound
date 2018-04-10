-------------------------------Sound Level Sensor-----------------------------
Sound level meter project made by Duc Anh LE, Feb.2018

This project uses a Raspberry Pi 3 Mode B as a sound sensor. A USB sound card
with microphone and an RJ45 cable are needed as peripherals. The alication
runs periodically every second and take record from microphone at a sample
rate of 16000 Hz. The sound is then calculated into 80 pieces of RMS value and
displayed as a bar chart on terminal screen. If communication is enable,
(conditional compilation), the sound will be re-calculated into 8 pieces of
Fast Level data and sent out to a PHP server program.

List of contents
1. Configuration Instructions
2. Installation Instructions
3. Operating Instructions
4. File manifest
5. Copyright and license
6. Contact Information


6. Contact Information
Duc Anh LE
Dept. of Information Technology
Vaasa University of Applied Sciences
Woffintie 30, Vaasa 65100, Finland
www.cc.puv.fi/~e1700679
e1700679@edu.vamk.fi
