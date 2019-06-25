#ifndef _DECK_H_
#define _DECK_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* _id2rank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
static const char* _id2suit[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};

static const int _num_ranks = 13;
static const int _num_suits = 4;
static const int _num_cards = 52;

typedef struct Card {

    int suit;
    int rank;

} card_t;

typedef struct Deck {

    card_t** cards;
    // original number of cards;
    int n;
    // index of next discard;
    int discard;
    // index of next draw;
    int draw;

} deck_t;

// creates k sets of decks;
deck_t* create_deck(int d);
card_t* create_card(int suit, int rank);

// shuffle decks;
// mode: 0 - all, 1 - remain, 2 - discard;
void shuffle_deck(deck_t* deck, int mode);

// draw a card from pile;
card_t* draw_card(deck_t* deck);

// add a card from pile, ignoring order;
// if discard, k is not decremented;
void add_card(deck_t* deck, card_t* card, int discard);

// clear deck;
void clear_deck(deck_t* deck);

void print_card(card_t* card);
void print_deck(deck_t* deck);

#endif