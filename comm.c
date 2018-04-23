#include "comm.h"
#include <math.h>
#include <stdio.h>
#include <curl/curl.h>

// function definition

/*
	This function takes in 80 pieces of rms value
	each is calculated by 200 samples.
	This function should use this value
	to recalculate 8 pieces of fast decibel value
	To do so, we need to put every 10 pieces of rms value
	square each of them and multiply by 200,
	accumulate to a sum, and then divide by 2000
	then square root the result.
*/

void sendToServer(double rms[]){
	double fast[8], sum; //define 8 fast dB value and their sum
	int i, j; // counter definition
	CURL *curl; // define curl object for transferring of data to server
	CURLcode res; // variable to check CURL connection
	char post[1000]; // string to save dB information for uploading to server

	for(i=0; i<8; i++){
		for(j=0, sum=0; j<10; j++){
			// calculate each piece over 200 pieces of dB data
			sum += rms[j+i*10]*rms[j+i*10]*200;
		}
		// calculate the corresponding fast dB value
		// and add to one element of the array
		fast[i] = sqrt(sum/2000);
	}
	// add up all fast dB values to string for later upload
	sprintf(post, "data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f",
		fast[0], fast[1], fast[2], fast[3], fast[4], fast[5], fast[6], fast[7]);

	// initialize connection to server
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl){ // if the connection has been successfully established
		// define the URL where the server locates
		curl_easy_setopt(curl, CURLOPT_URL, URL);
		// define the content to upload, here is the post string
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		// now upload to server
		res = curl_easy_perform(curl);
		if(res != CURLE_OK){ // if the upload is not successful
			// define the error
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
			// inform about the error
			curl_easy_strerror(res));
			// delete the old upload archive
			curl_easy_cleanup(curl);
		}
		// clean up to finish the upload
		curl_global_cleanup();
	}
}
