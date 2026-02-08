#include "ptyman.h"

void drawrandomdots(int n, int cols, int rows) {
	for (int i = 0; i < n; i++) {
		int x = (rand() % cols) + 1;
		int y = (rand() % rows) + 1;
		printf("\033[%d;%dH\033[41m \033[0m", y,x);
	}
}

int main() {
	termios termios_settings;
	enableRawMode(&termios_settings);

	int cols;
	int rows;
	char c;

	getwindowsize(&cols, &rows);
	rows -= 2;

	t_player player1;
	t_player player2;

	player_set_zero(&player1);
	player_set_zero(&player2);

	player1.x = 1;
	player1.y = 1;
	player1.eatcount = 0;
	player1.bgcolor = 106;
	player1.fgcolor = 30;
	player1.icon = '@';

	player2.x = cols;
	player2.y = 1;
	player2.eatcount = 0;
	player2.bgcolor = 105;
	player2.fgcolor = 30;
	player2.icon = '!';

	screen_loading(cols,rows);
	screen_footer(cols,rows);

	while (1) {
		screen_cell_clear(player1.old_x, player1.old_y);
		screen_cell_clear(player2.old_x, player2.old_y);

		player_print(player1);
		player_print(player2);
		fflush(stdout);
		
		player1.old_x = player1.x;
		player1.old_y = player1.y;

		player2.old_x = player2.x;
		player2.old_y = player2.y;

		if (read(STDIN_FILENO, &c, 1) == 1) {

			if (c == '\033') {
				char seq[2];
				read(STDIN_FILENO, &seq[0], 1) == 0;
				read(STDIN_FILENO, &seq[1], 1) == 0;

				if (seq[0] == '[') {
					if (seq[1] == 'A' && player2.y > 1) player2.y--;
					if (seq[1] == 'B' && player2.y < rows) player2.y++;
					if (seq[1] == 'C' && player2.x < cols) player2.x++;
					if (seq[1] == 'D' && player2.x > 1) player2.x--;
				}
			}
			if (c == 'w' && player1.y > 1) player1.y--;
			if (c == 's' && player1.y < rows) player1.y++;
			if (c == 'a' && player1.x > 1) player1.x--;
			if (c == 'd' && player1.x < cols) player1.x++;
			if (c == 'q') break;
		}
	}
	disableRawMode(&termios_settings);
	return 0;
}
