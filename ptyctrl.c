#include "ptyman.h"

void disableRawMode(termios *termios_settings) {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, termios_settings);
	printf("\033[?1049l");
	printf("\033[?25h");
}

void enableRawMode(termios *termios_settings) {
	tcgetattr(STDIN_FILENO, termios_settings);
	// atexit(disableRawMode);

	struct termios raw = *termios_settings;
	raw.c_lflag &= ~(ECHO | ICANON);
	
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	
	printf("\033[?1049h");
	printf("\033[?25l");
}