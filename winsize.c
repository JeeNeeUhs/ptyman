#include "ptyman.h"

void getwindowsize(int *cols, int *rows) {
	struct winsize w;
	ioctl(1, TIOCGWINSZ, &w);
	*cols = w.ws_col;
	*rows = w.ws_row;
	return;
}