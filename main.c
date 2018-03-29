// This file contains the main function of our project
#include "sound.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
	int ret;
	while(1){ //loop forever
		// run system command "arecord" to record 1 second of wav
		ret = system("arecord -r16000 -c1 -f S16_LE -d1 test.wav");
		if(WIFSIGNALED(ret) && (WTERMSIG(ret) == SIGINT)) break;
		// display wav header
		dispWAVheader("test.wav");
		// display wav strength as decibel value
		dispWAVdata("test.wav");
		// break; // loop runs just once
	}
	return 0;
}
