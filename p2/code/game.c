#include "game.h"

// game utils;
// ================================================================================================================ //

void print_cards(list_t* list) {

    if (list->n == 0) {
        printf("[null]\n");
        return;
    }
    node_t* node = list->head;
    int first = 1;
    while (first || node != list->head) {
        if (first) {
            first = 0;
        }
        printf("[%s - %s] ", _id2suit[node->id], _id2rank[node->val]);
        node = node->next;
    }
    printf("\n");

}



// game logic;
// ================================================================================================================ //

game_t* initialize_game(int r, int c, int n, int mode) {

    game_t* game = malloc(sizeof(game_t));

    game->mode = mode;

    game->r = r;
    game->c = c;
    game->n = n;
    game->dir = 0;

    game->deck = create_deck(2);
    shuffle_deck(game->deck, 0);
    game->players = malloc(n * sizeof(player_t*));

    int k, i;
    player_t* player;
    card_t* card;
    node_t* node;
    for (k = 0; k < n; k++) {
        player = malloc(sizeof(player_t));

        player->cards = create_list();
        for (i = 0; i < c; i++) {
            card = draw_card(game->deck);
            node = create_node(card->suit, card->rank);
            insert_node(player->cards, node);
            free(card);
        }

        player->score = 0;
        game->players[k] = player;
    }

    int val = 0, ind = 0;
    for (k = 0; k < n; k++) {
        card = draw_card(game->deck);
        if (val > card->suit * _num_ranks + card->rank) {
            ind = k;
            val = card->suit * _num_ranks + card->rank;
        }
        add_card(game->deck, card, 1);
    }

    game->cur_player = ind;

    card = draw_card(game->deck);
    game->cur_rank = card->rank;
    game->cur_suit = card->suit;
    add_card(game->deck, card, 1);

    game->attack = 0;

    return game;

}

// clear decks, player cards, shuffle;
void restart_game(game_t* game, int winner) {

    int i, j;
    card_t* card;
    node_t* node;
    // recover and shuffle deck;
    clear_deck(game->deck);
    game->deck = create_deck(2);
    shuffle_deck(game->deck, 0);
    // initial draw of players;
    for (i = 0; i < game->n; i++) {
        clear_list(game->players[i]->cards);
        game->players[i]->cards = create_list();
        for (j = 0; j < game->c; j++) {
            card = draw_card(game->deck);
            node = create_node(card->suit, card->rank);
            insert_node(game->players[i]->cards, node);
            free(card);
        }
    }
    // set current player;
    game->cur_player = winner;
    game->attack = 0;

}

void player_draw_cards(game_t* game) {

    player_t* player = game->players[game->cur_player];
    int num = MAX(game->attack, 1);

    printf("Player %d draws %d card(s)...\n", game->cur_player, num);

    int i;
    card_t* card;
    node_t* node;
    for (i = 0; i < num; i++) {
        card = draw_card(game->deck);
        node = create_node(card->suit, card->rank);
        insert_node(player->cards, node);
        free(card);
    }

    printf("%d cards remaining, %d cards in discard pile\n", game->deck->n - game->deck->draw, game->deck->discard);

}


int update_states(game_t* game, node_t* card_node) {

    // invalid card;
    // player draws cards from deck;
    /*
     1. no card;
     2. suit does not match;
     3. rank does not match;
     4. normal cards in attack mode;
     */
    if (card_node == NULL || (game->cur_suit != card_node->id && game->cur_rank != card_node->val) ||
        (game->attack > 0 && !(card_node->val == 0 || card_node->val == 1 || card_node->val == 5 || card_node->val == 9 || card_node->val == 10))) {
        
        player_draw_cards(game);
        game->attack = 0;

        // update current player;
        if (game->dir == 0) {
            game->cur_player = game->cur_player >= game->n - 1 ? 0 : game->cur_player + 1;
        }
        else {
            game->cur_player = game->cur_player <= 0 ? game->n - 1 : game->cur_player - 1;
        }

        return -1;
    }

    // valid card;
    printf("Player %d plays [%s - %s]\n", game->cur_player, _id2suit[card_node->id], _id2rank[card_node->val]);
    // current player;
    int player_ind = game->cur_player;
    player_t* player = game->players[player_ind];

    // remove from player's pile;
    remove_node(player->cards, card_node);
    card_t* card = create_card(card_node->id, card_node->val);
    free(card_node);

    // add card in discard mode;
    add_card(game->deck, card, 1);
    game->cur_suit = card->suit;
    game->cur_rank = card->rank;

    // attack and reverse;
    if (card->rank == 0 || card->rank == 1) {
        game->attack += card->rank + 2;
    }
    else if (card->rank == 10) {
        game->dir = (1 + game->dir) % 2;
    }
    
    // update current player;
    if (game->dir == 0) {
        game->cur_player = game->cur_player >= game->n - 1 ? 0 : game->cur_player + 1;
    }
    else {
        game->cur_player = game->cur_player <= 0 ? game->n - 1 : game->cur_player - 1;
    }
    // skip the next player;
    if (card->rank == 9) {
        if (game->dir == 0) {
            game->cur_player = game->cur_player >= game->n - 1 ? 0 : game->cur_player + 1;
        }
        else {
            game->cur_player = game->cur_player <= 0 ? game->n - 1 : game->cur_player - 1;
        }
    }
    
    // the player who plays the card;
    if (game->players[player_ind]->cards->n <= 0) {
        return player_ind;
    }

    return -1;

}


void play_game(game_t* game) {

    int r, i, winner;
    int played;

    player_t* player;
    card_t* card;
    node_t* card_node;
    
    for (r = 0; r < game->r; r++) {
        printf("------- Round %d -------\n", r + 1);
        if (game->mode == 0) {
            puts("PRINT CARDS");
            for (i = 0; i < game->n; i++) {
                printf("Player %d:\n", i);
                print_cards(game->players[i]->cards);
            }
        }
        puts("PRINT PLAYERS");
        for (i = 0; i < game->n; i++) {
            printf("[Player %d: %d]\n", i, game->players[i]->score);
        }
        winner = -1;
        while (winner < 0) {
            player = game->players[game->cur_player];
            printf("Player %d:\n", game->cur_player);
            printf("Current card = [%s - %s], Attack = %d\n", _id2suit[game->cur_suit], _id2rank[game->cur_rank], game->attack);
            print_cards(player->cards);
            // play card;
            // demo mode;
            if (game->mode == 0) {
                card_node = demo_play_card(game);
            }
            // play mode;
            else {
                scanf("%d", &played);
                if (played == -1 || played >= player->cards->n) {
                    card_node = NULL;
                }
                else if (played < -1) {
                    end_game(game);
                    return;
                }
                else {
                    card_node = player->cards->head;
                    for (i = 0; i < played; i++) {
                        card_node = card_node->next;
                    }
                }
            }
            // update states;
            winner = update_states(game, card_node);
            if (winner < 0) {
                print_cards(player->cards);
            }
        }
        printf("WINNER: Player %d\n", winner);
        // apply penalties;
        for (i = 0; i < game->n; i++) {
            game->players[i]->score = game->players[i]->score - game->players[i]->cards->n;
        }
        if (game->mode == 0) {
            puts("PRINT CARDS");
            for (i = 0; i < game->n; i++) {
                printf("Player %d:\n", i);
                print_cards(game->players[i]->cards);
            }
        }
        restart_game(game, winner);
    }

    end_game(game);

}


void end_game(game_t* game) {

    int i, j, count = 0, max_score = 1;
    // announce winner;
    int winners[game->n];
    player_t* player;
    for (i = 0; i < game->n; i++) {
        if (max_score > 0 || game->players[i]->score == max_score) {
            // add winner;
            winners[count++] = i;
            // initial;
            if (max_score > 0) {
                max_score = game->players[i]->score;
            }
        }
        else if (game->players[i]->score > max_score) {
            // change current max score, update players;
            for (j = 0; j < count; j++) {
                winners[j] = 0;
            }
            count = 0;
            max_score = game->players[i]->score;
            winners[count++] = i;
        }
    }
    // announce winner;
    puts("------- Winners -------");
    for (i = 0; i < count; i++) {
        printf("Player %d\n", winners[i]);
    }
    printf("Max score: %d\n", max_score);

    // clear player;
    for (i = 0; i < game->n; i++) {
        clear_list(game->players[i]->cards);
        free(game->players[i]);
    }
    free(game->players);
    // clear deck;
    clear_deck(game->deck);
    // clear game;
    free(game);

}



// demo utils;
/*
 attack -> match suit -> match rank;
 */
// ================================================================================================================ //

node_t* demo_play_card(game_t* game) {

    node_t* node = NULL;
    player_t* player = game->players[game->cur_player];
    
    // attack;
    puts(":\t\t\ttrying to attack...");
    node = find_attack(player->cards);
    
    // suit;
    if (node == NULL || (node->id != game->cur_suit && node->val != game->cur_rank)) {
        puts(":\t\t\ttrying to match suit...");
        node = find_match(player->cards, game->cur_suit, 0);
    }
    
    // rank;
    if (node == NULL || (node->id != game->cur_suit && node->val != game->cur_rank)) {
        puts(":\t\t\ttrying to match rank...");
        node = find_match(player->cards, game->cur_rank, 1);
    }

    return node;

}

node_t* find_attack(list_t* cards) {

    if (cards->n == 0) {
        return NULL;
    }

    node_t* card = cards->head;
    int first = 1;
    while (first || card != cards->head) {
        if (first) {
            first = 0;
        }
        if (card->val == 0 || card->val == 1 || card->val == 9 || card->val == 10) {
            return card;
        }
        card = card->next;
    }

    return NULL;

}

// 0: suit, 1: rank;
node_t* find_match(list_t* cards, int target, int mode) {

    if (cards->n == 0) {
        return NULL;
    }

    node_t* card = cards->head;
    int first = 1, match;
    while (first || card != cards->head) {
        if (first) {
            first = 0;
        }
        match = (mode == 0) ? card->id : card->val;
        if (match == target) {
            return card;
        }
        card = card->next;
    }

    return NULL;

}
