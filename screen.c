#include "screen.h"
#include <stdio.h>

/*
	Function definition of clearScreen()
	This function uses VT100 escape sequence \ESC[2J
	to make the whole terminal screen empty.
	Argument: no
	Return: no
*/
void clearScreen(){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*
	Function definition of gotoxy()
	This function uses VT100 escape sequence \ESC[row;colH
	to set cursor to a specific location on the terminal screen.
	Argument:	row number, 1 is top row
			col number, 1 is left column
	Return: no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/*
	Function definition of setColor()
	This function uses VT100 escape sequence \ESC[1;colorm
	to set color of the text at the current cursor position
	Argument: color code from 30 to 37 (black to white)
	Return: no
*/
void setColor(int color){
	if(color >= BLACK && color <= WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
	}
}

/*
	This function displays a vertical bar for the given dB value.
	The value varies between 30 and 90,
	so we need to render 3dB for one row
	and 90dB will be displayed as bar of 30 rows.
	Argument:	column number
			signal in decibel
	Return: no
*/
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
