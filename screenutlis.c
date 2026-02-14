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

void screen_footer(t_game game) {
	for (int i = 0; i < game.cols; i++) {
		printf("\033[\033[%d;%dH-", game.rows + 1, 0 + i);
	}
	printf("\033[\033[%d;%dH bu kodu unix terminal anatomisi sinifi yazmistir", game.rows + 2, 10);

	fflush(stdout);
}

void screen_footer_update (t_game game, t_player p1, t_player p2) {
	int rightpos = (game.p2->eatcount > 9) ? game.cols - 13 : game.cols - 12;
	printf("\033[\033[%d;%dH\033[30m\033[43mPlayer 1: %d\033[0m", game.rows + 2, 2, p1.eatcount);
	printf("\033[\033[%d;%dH\033[30m\033[45mPlayer 2: %d\033[0m", game.rows + 2, rightpos, p2.eatcount);
	fflush(stdout);
}

void screen_random_dots(int n, t_coordinates *apple, int cols, int rows) {
	for (int i = 0; i < n; i++) {
		apple[i].x = (rand() % cols) + 1;
		apple[i].y = (rand() % rows) + 1;
		printf("\033[%d;%dH\033[41m \033[0m", apple[i].y, apple[i].x);
	}
}
