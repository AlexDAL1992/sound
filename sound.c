#include "comm.h"
#include "sound.h"
#include "screen.h"
#include <stdio.h>
#include <math.h>

void printID(char id[]){
	int i;
	for(i = 0; i < 4; i++)
		printf("%c", id[i]);
	printf("\n");
}

// function definition of dispWAVdata()
void dispWAVdata(char filename[]){
	int i, j; // loop counters
	FILE *fp; // file handler to open the file "test.wav"
	double rms[80], sum; // 80 pieces of RMS values
	short samples[SAMPLERATE]; // total 16000 samples in 1 second
	WAVheader mh; // used to skip over the header of the wav file

	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error when opening the file.");
		return;
	}
	fread(&mh, sizeof(mh), 1, fp);
	fread(samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);

	clearScreen();
	for(i = 0; i < 80; i++){
		for(j = 0, sum = 0.0; j < 200; j++){
			sum += samples[i*200+j]*samples[i*200+j];
		}
		rms[i] = sqrt(sum/200);
#ifdef DEBUG
		printf("rms[%d]: %10.4f, dB = %10.4f\n", i, rms[i], 20*log10(rms[i]));
#else
		dispBar(i, 20*log10(rms[i]));
#endif
	}

#ifdef COMM
	sendToServer(rms);
#endif
}

// function definition of dispWAVheader()
void dispWAVheader(char filename[]){
	FILE *fp;
	WAVheader mh; // an instance of WAVheader struct

	// open the test.wav file for reading
	fp = fopen(filename, "r");
	if(fp == NULL){ // if fopen fails
		printf("Error when opening the file.");
		return; // function stops here
	}
	fread(&mh, sizeof(mh), 1, fp);
	fclose(fp); // close the opened file
	printf("Chunk ID: ");
	printID(mh.chunkID);
	printf("Chunk size: %d\n", mh.chunkSize);
	printf("Format: ");
	printID(mh.format);
	printf("  subchunk 1 ID: ");
	printID(mh.subchunk1ID);
	printf("  subchunk 1 size: %d\n", mh.subchunk1Size);
	printf("Audio format: %d\n", mh.audioFormat);
	printf("Number of channels: %d\n", mh.numChannels);
	printf("Sample rate: %d\n", mh.sampleRate);
	printf("Byte rate: %d\n", mh.byteRate);
	printf("Block align: %d\n", mh.blockAlign);
	printf("Bits per sample: %d\n", mh.bitsPerSample);
	printf("  subchunk 2 ID: ");
	printID(mh.subchunk2ID);
	printf("  subchunk 2 size: %d\n", mh.subchunk2Size);
}
