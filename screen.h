#define UNICODE // use unicode to make good looking bars
#define BAR "\u2590"
// constant definition
#define ESC 0x1b
enum COLORS {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

// functions prototype
void clearScreen();
void gotoxy(int row, int col);
void setColor(int color);
void dispBar(int col, double dB);
