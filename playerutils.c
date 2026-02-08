#include "ptyman.h"

void player_set_zero(t_player *p) {
	p->x = 0;
	p->y = 0;
	p->eatcount = 0;
	p->icon = 0;
	p->fgcolor = 0;
	p->bgcolor = 0;
	p->old_x = 0;
	p->old_y = 0;
}

void player_print(t_player p) {
	printf("\033[%d;%dH\033[%dm\033[%dm%c\033[0m", p.y, p.x, p.bgcolor, p.fgcolor, p.icon);
	fflush(stdout);
}