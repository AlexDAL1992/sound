//#define DEBUG	// conditional compiling
// constant definition
#define SAMPLERATE 16000

// structure definition
typedef struct{
	char chunkID[4]; //RIFF
	unsigned int chunkSize;
	char format[4];
	char subchunk1ID[4];
	unsigned char subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2ID[4];
	unsigned int subchunk2Size;
	
}WAVheader;
//function prototype
void dispWAVheader(char filename[]);
void dispWAVdata(char filename[]);
void printID(char []);
