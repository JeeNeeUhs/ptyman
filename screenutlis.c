#include "ptyman.h"

void screen_cell_clear(int x, int y) {
	printf("\033[\033[%d;%dH ", y, x);
}

void screen_loading(int cols, int rows) {
	printf("\033[2J");
	
	printf("\033[\033[%d;%dH\033[43m\033[30m¯\\_(ツ)_/¯\033[0m", (rows + 2) / 2, (cols / 2) - 5);
	fflush(stdout);
	
	sleep(1);

	printf("\033[2J");
}

void screen_footer(int cols, int rows) {
	for (int i = 0; i < cols; i++) {
		printf("\033[\033[%d;%dH-", rows + 1, 0 + i);
	}
	printf("\033[\033[%d;%dH bu kodu unix terminal anatomisi sinifi yazmistir", rows + 2, 0);

	drawrandomdots(10, cols,rows);
	fflush(stdout);
}
