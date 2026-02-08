#include "ptyman.h"

static int check_apple(t_game game, int x, int y) {
	for (int i = 0; i < 10; i++) {
		if (game.apple[i].x == x && game.apple[i].y == y) {
			return 1;
		}
	}
	return 0;
}

static int check_player(t_game game, t_player *player, int x, int y) {
	if (game.p1 == player) {
		if (game.p2->x == x && game.p2->y == y) {
			return 1;
		}
	} else {
		if (game.p1->x == x && game.p1->y == y) {
			return 1;
		}
	}
	return 0;
}

void move_player(t_game game, t_player *player, char direction) {
	switch (direction) {
		case 'w':
			if (check_apple(game, player->x, player->y - 1))
				player->eatcount++;
			if (!check_player(game, player, player->x, player->y - 1))
				player->y--;
			break;
		case 'a':
			if (check_apple(game, player->x - 1, player->y))
				player->eatcount++;
			if (check_player(game, player, player->x - 1, player->y))
				player->x--;
		case 's':
			if (check_apple(game, player->x, player->y + 1))
				player->eatcount++;
			if (!check_player(game, player, player->x, player->y + 1))
				player->y++;
			break;
		case 'd':
			if (check_apple(game, player->x + 1, player->y))
				player->eatcount++;
			if (!check_player(game, player, player->x + 1, player->y))
				player->x++;
			break;
	}
}