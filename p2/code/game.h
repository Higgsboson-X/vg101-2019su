#ifndef _GAME_H_
#define _GAME_H_

#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x < y ? x : y

#include "list.h"
#include "deck.h"
#include "list.h"

typedef struct Player {

    list_t* cards;
    int score;

} player_t;

typedef struct Game {

    // 0: demo, 1: game
    int mode;

    int r;
    int c;
    int n;
    int dir;
    // draw deck and discard pile;
    deck_t* deck;
    player_t** players;
    int cur_player;

    int cur_suit;
    int cur_rank;

    int attack;

} game_t;

/*
    r: rounds;
    c: initial number of cards;
    n: number of players;
    dir:
        0: next;
        1: prev;
*/
game_t* initialize_game(int r, int c, int n, int mode);

// id: suit, val: rank;
// 0: demo, 1: play;
void play_game(game_t* game);
void restart_game(game_t* game, int winner);
int update_states(game_t* game, node_t* card_node);
node_t* demo_play_card(game_t* game);
void end_game(game_t* game);

void player_draw_cards(game_t* game);

// find functional cards;
node_t* find_attack(list_t* cards);
// 0: suit, 1: rank;
node_t* find_match(list_t* cards, int target, int mode);

void print_cards(list_t* cards);

#endif