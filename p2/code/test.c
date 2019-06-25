#include "list.h"
#include "deck.h"
#include "game.h"

void test_list() {

	srand(time(NULL));

	list_t* list = create_list();
	node_t* node;

	int i, j;

	printf(">>>>>>> Insert <<<<<<<\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 13; j++) {
			node = create_node(13 * i + j, rand() % 13);
			insert_node(list, node);
			printf("Inserted node:\n");
			print_node(node);
			// print_list(list);
			// getc(stdin);
		}
	}

	print_list(list);

	printf(">>>>>>> Remove <<<<<<<\n");
	node_t* del;
	node = list->head;
	for (i = 0; i < 13; i++) {
		if (node->val >= 3) {
			remove_node(list, node);
			del = node;
			node = list->head;
			printf("Deleted node:\n");
			print_node(del);
			free(del);
			// print_list(list);
			// getc(stdin);
		}
		else {
			node = node->next;
		}
	}

	print_list(list);

	clear_list(list);

}


void test_deck() {

	deck_t* deck = create_deck(2);
	
	printf(">>>>>>> Create <<<<<<<\n");
	print_deck(deck);

	printf(">>>>>>> Shuffle <<<<<<<\n");
	shuffle_deck(deck, 0);

	print_deck(deck);

	int i;
	card_t* card;

	printf(">>>>>>> Draw <<<<<<<\n");
	for (i = 0; i < 21; i++) {
		card = draw_card(deck);
		print_card(card);
		print_deck(deck);
		add_card(deck, card, 1);
	}

	print_deck(deck);
	shuffle_deck(deck, 1);
	print_deck(deck);
	shuffle_deck(deck, 2);
	print_deck(deck);

	clear_deck(deck);

}


void test_game() {

	game_t* game = initialize_game(3, 3, 3, 1);
	play_game(game);

}



int main() {

	// test_list();
	// test_deck();
	test_game();

	return 0;

}