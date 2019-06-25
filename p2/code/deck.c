#include "deck.h"



deck_t* create_deck(int d) {

    deck_t* deck = malloc(sizeof(deck_t));
    deck->cards = malloc(d * _num_cards * sizeof(card_t*));
    deck->n = d * _num_cards;
    deck->discard = 0;
    deck->draw = 0;

    int i, j, k;
    card_t* card;
    for (k = 0; k < d; k++) {
        for (i = 0; i < _num_suits; i++) {
            for (j = 0; j < _num_ranks; j++) {
                card = malloc(sizeof(card_t));
                card->suit = i;
                card->rank = j;
                deck->cards[k * _num_cards + i * _num_ranks + j] = card;
            }
        }
    }

    return deck;

}


card_t* create_card(int suit, int rank) {

    card_t* card = malloc(sizeof(card_t));
    card->suit = suit;
    card->rank = rank;

    return card;

}


void shuffle_deck(deck_t* deck, int mode) {

    // one card or no card;
    if (deck->draw == deck->n || deck->draw == deck->n - 1) {
        return;
    }

    srand(time(NULL));

    card_t* card;

    int i, j;

    int s = (mode <= 1) ? 0 : deck->draw;
    int e = (mode == 0 || mode == 2) ? deck->n : deck->discard;

    for (i = s; i < e; i++) {
        j = s + rand() % (e - s);
        if (deck->cards[i] == NULL || deck->cards[j] == NULL) {
            perror("Card missing");
            return;
        }
        if (i != j) {
            // swap cards;
            card = deck->cards[i];
            deck->cards[i] = deck->cards[j];
            deck->cards[j] = card;
        }
    }

}

card_t* draw_card(deck_t* deck) {

    if (deck->draw == deck->n) {
        // shuffle discard pile;
        if (deck->discard == 0) {
            perror("Empty discard pile");
            return NULL;
        }
        int i;
        int n = deck->discard - 1;
        for (i = n; i >= 0; i--) {
            add_card(deck, deck->cards[i], 0);
            if (deck->draw > i) {
                deck->cards[i] = NULL;
            }
        }
        shuffle_deck(deck, 1);
    }

    card_t* card = deck->cards[deck->draw];
    deck->cards[deck->draw++] = NULL;

    return card;

}

void add_card(deck_t* deck, card_t* card, int discard) {

    if (discard) {
        if (deck->cards[deck->discard] != NULL) {
            perror("No place to discard");
            return;
        }
        deck->cards[deck->discard++] = card;
        return;
    }

    if (deck->cards[deck->draw - 1] != NULL) {
        perror("No place to return");
        return;
    }
    deck->cards[--deck->draw] = card;

}

void clear_deck(deck_t* deck) {

    int i;
    for (i = 0; i < deck->n; i++) {
        if (deck->cards[i] != NULL) {
            free(deck->cards[i]);
        }
    }
    free(deck->cards);
    free(deck);

}


void print_card(card_t* card) {

    printf("[%s - %s]\n", _id2suit[card->suit], _id2rank[card->rank]);

}


void print_deck(deck_t* deck) {

    int i;
    printf("PRINT DECK [DISCARD %d - DRAW - %d]\n", deck->discard, deck->draw);
    for (i = 0; i < deck->n; i++) {

        if (deck->cards[i] == NULL) {
            printf(" [null] ");
        }
        else {
            printf(" [%s - %s] ", _id2suit[deck->cards[i]->suit], _id2rank[deck->cards[i]->rank]);
        }

        if (i > 0 && i % 4 == 0) {
            printf("\n");
        }

    }

    printf("\n");

}