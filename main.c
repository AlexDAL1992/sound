// This file contains the main function of our project
#include "sound.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	while(1){ //loop forever
		// run system command "arecord" to record 1 second of wav
		system("arecord -r16000 -c1 -f S16_LE -d1 test.wav");
		// display wav header
		dispWAVheader("test.wav");
		// display wav strength as decibel value
		dispWAVdata("test.wav");
		break; // loop runs just once
	}
	return 0;
}
