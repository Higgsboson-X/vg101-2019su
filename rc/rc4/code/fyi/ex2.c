#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

char* RANK[13] = {"A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K "};
char* SUIT[4] = {"Diamonds", "Clubs", "Spades", "Heart"};

typedef struct Card {

	int rank;
	int suit;


} card_t;


void print_shape(int suit) {

	if (suit == 0) {

		// diamonds;
		printf("|        /\\        |\n");
		printf("|       /  \\       |\n");
		printf("|      /    \\      |\n");
		printf("|      \\    /      |\n");
		printf("|       \\  /       |\n");
		printf("|        \\/        |\n");

	}
	else if (suit == 1) {

		// clubs;
		printf("|        __        |\n");
		printf("|      _/  \\_      |\n");
		printf("|     /      \\     |\n");
		printf("|     \\______/     |\n");
		printf("|        ||        |\n");
		printf("|       ----       |\n");

	}

	else if (suit == 2) {

		// spades;
		printf("|        /\\        |\n");
		printf("|       /  \\       |\n");
		printf("|      /    \\      |\n");
		printf("|      \\_  _/      |\n");
		printf("|        ||        |\n");
		printf("|       ----       |\n");

	}

	else {

		// heart;
		printf("|     __  __       |\n");
		printf("|    /  \\/  \\      |\n");
		printf("|   /        \\     |\n");
		printf("|   \\        /     |\n");
		printf("|    \\      /      |\n");
		printf("|     \\____/       |\n");

	}

}


void print_card(card_t* card) {

	printf(" __________________ \n");
	printf("|%s                |\n", RANK[card->rank]);

	int space = 2, i;

	for (i = 0; i < space; i++) {
		printf("|                  |\n");
	}

	print_shape(card->suit);

	for (i = 0; i < space; i++) {
		printf("|                  |\n");
	}

	printf("|                %s|\n", RANK[card->rank]);
	printf("|__________________|\n\n");

}


void swap_cards(card_t** deck, int i, int j) {

	card_t* card = deck[i];
	deck[i] = deck[j];
	deck[j] = card;

}


void shuffle_deck(card_t** deck, int remaining) {

	int i, j;
	for (i = 0; i < remaining; i++) {
		j = rand() % remaining;
		swap_cards(deck, i, j);
	}

}


void play() {

	char buf;

	card_t** deck = malloc(52 * sizeof(card_t*));
	card_t* card;

	int i, j, remaining = 52;

	for (i = 0; i < 13; i++) {
		for (j = 0; j < 4; j++) {
			card = malloc(sizeof(card_t));
			card->rank = i;
			card->suit = j;
			deck[4 * i + j] = card;
		}
	}

	srand(time(NULL));

	buf = getc(stdin);

	while (buf != 'q') {
		card = deck[0];
		printf("%c Drawing a card...\n", buf);
		print_card(card);
		swap_cards(deck, 0, --remaining);
		if (remaining <= 0) {
			printf("All cards drawn, initializing...\n");
			remaining = 52;
		}
		printf("Shuffling...\n");
		shuffle_deck(deck, remaining);

		buf = getc(stdin);
	}

	for (i = 0; i < 13; i++) {
		for (j = 0; j < 4; j++) {
			free(deck[4 * i + j]);
		}
	}

	free(deck);

}


void test_print() {

	card_t* card = malloc(sizeof(card_t));

	int i, j;
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 4; j++) {
			card->rank = i;
			card->suit = j;
			print_card(card);
		}
	}

	free(card);

}



int main() {

	// test_print();
	play();

	return 0;

}





