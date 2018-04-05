#include "screen.h"
#include <stdio.h>

void clearScreen(){
	printf("%c[2J", ESC);
	fflush(stdout);
}

void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

void setColor(int color){
	if(color >= BLACK && color <= WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
	}
}

// This function displays a vertical bar for the given dB value.
// The value varies between 30 and 90,
// so we need to render 3dB for one row
// and 90dB will be displayed as bar of 30 rows.
void dispBar(int col, double dB){
	int i;
	for(i=0; i<dB/3; i++){
		gotoxy(30-i, col+1);
#ifndef UNICODE // if unicode is not enabled
		printf("%c", '*');
#else
		printf("%s", BAR);
#endif
	}
}