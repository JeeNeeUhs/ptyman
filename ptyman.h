#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

typedef struct termios termios;

typedef struct	s_coordinates {
	int x;
	int y;
}				t_coordinates;

typedef struct	s_player {
	int		x;
	int		y;

	int		old_x;
	int		old_y;

	int		eatcount;

	int		bgcolor;
	int		fgcolor;
	char	icon;
}				t_player;

typedef struct	s_game {
	t_player *p1;
	t_player *p2;
	t_coordinates *apple;
	int cols;
	int rows;
}				t_game;

//ptyctrl.c
void enableRawMode(termios *termios_settings);
void disableRawMode(termios *termios_settings);

//winsize.c
void getwindowsize(int *cols, int *rows);

//playerutils.c
void player_set_zero(t_player *p);
void player_print(t_player p);

//screenutils.c
void screen_cell_clear(int x, int y);
void screen_loading(int cols, int rows);
void screen_footer(t_game game);
void screen_footer_update (t_game game, t_player p1, t_player p2);
void screen_random_dots(int n, t_coordinates *apple, int cols, int rows);

//move.c
void move_player(t_game game, t_player *player, char direction);

//main.c
void getwindowsize(int *cols, int *rows);