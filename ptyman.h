#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

typedef struct termios termios;

typedef struct s_player {
	int		x;
	int		y;

	int		old_x;
	int		old_y;

	int		eatcount;

	int		bgcolor;
	int		fgcolor;
	char	icon;
}		t_player;

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
void screen_footer(int cols, int rows);

//main.c
void getwindowsize(int *cols, int *rows);
void drawrandomdots(int n, int cols, int rows);