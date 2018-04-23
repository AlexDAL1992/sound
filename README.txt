-------------------------------Sound Level Sensor-----------------------------
Sound level meter project made by Duc Anh LE, 22nd Feb.2018

This project uses a Raspberry Pi 3 Mode B as a sound sensor. A USB sound card
with microphone and an RJ45 cable are needed as peripherals. The application
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



1. Configuration Instructions
	Hardware:
	- Rasberry Pi 3 model B device
	- USB external sound card
	- Microphone with 3.5mm connector
	- MicroSD card containing the Sound Level project
	- Internet connection, Ethernet cable recommended
	- 5V DC USB power supply or equivalent
	
	Software:
	- Sound Level project
	- Linux environment



2. Installation Instructions
	- Connect the Raspberry Pi 3 device to Ethernet cable with internet
	- Insert the microSD card containing the Sound Level project to the
	Rasberry Pi device
	- Attach the USB sound card to one USB port in the Rasberry Pi device
	- Connect the microphone to the right microphone slot in the sound card
	- Turn on the Raspberry Pi device by connecting it to the power supply
	- Make sure the sound card and microphone are all turned on
	- Watch the internet connection if successfully established
	as the LAN LED on the Raspberry Pi blinks.



3. Operating Instructions
	- Check the IP address of the Raspberry Pi enclosed in an email
	sent to configured email address inbox
	- Access to Raspberry Pi by logging in with its IP address
	and personal account
	- Point to the project folder and create the application
	- Run the application already created before
	- Make some noise and record it with the microphone
	- See the results displayed on the computer screen



4. File manifest
	- C-language source code files: main.c, screen.c, sound.c, comm.c
	- C-language library files: screen.h, sound.h, comm.h
	- Information files: README.md, README.txt
	- Compiling file: makefile



5. Copyright and license
	Copyright (c) 2018, Duc Anh LE
	
	Permission is granted to copy, distribute and/or modify this document
	under the terms of the GNU Free Documentation License, Version 1.3
	or any later version published by the Free Software Foundation;
	with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.

	

6. Contact Information
		Duc Anh LE
	Department of Information Technology
	Vaasa University of Applied Sciences
	Woffintie 30, Vaasa 65100, Finland
	www.cc.puv.fi/~e1700679
	e1700679@edu.vamk.fi
