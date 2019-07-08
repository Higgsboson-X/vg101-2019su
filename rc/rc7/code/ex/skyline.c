#include <stdio.h>
#include <stdlib.h>

typedef struct Building {
	int left;
	int height;
	int right;
} building_t;

typedef struct Strip {
	int left;
	int height;
} strip_t;

typedef struct Skyline {
	strip_t* strips;
	int n;
} skyline_t;


int max(int a, int b) {
	return (a < b) ? b : a;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}


// ================================================================== //
skyline_t* merge_skylines(skyline_t* s1, skyline_t* s2) {

	if (s1->n == 0) {
		// free(s1->strips);
		free(s1);
		return s2;
	}
	if (s2->n == 0) {
		// free(s2->strips);
		free(s2);
		return s1;
	}

	skyline_t* s = (skyline_t*)calloc(1, sizeof(skyline_t));
	s->n = 0;
	s->strips = (strip_t*)calloc((s1->n + s2->n), sizeof(strip_t));

	strip_t* strips1 = s1->strips;
	strip_t* strips2 = s2->strips;
	int h1 = 0,
		h2 = 0;
	int i = 0,
		j = 0,
		l = 0,
		h = 0;
	int update1 = 0,
		update2 = 0;
	while (i < s1->n && j < s2->n) {
		update1 = (int)(strips1[i].left <= strips2[j].left);
		update2 = (int)(strips2[j].left <= strips1[i].left);
		// left boundary;
		l  = update1 ? strips1[i].left : strips2[j].left;
		// update h;
		h1 = update1 ? strips1[i].height : h1;
		h2 = update2 ? strips2[j].height : h2;

		i = update1 ? i + 1 : i;
		j = update2 ? j + 1 : j;

		if (h != max(h1, h2)) {
			// not redundant;
			h = max(h1, h2);
			s->strips[s->n++] = (strip_t){l, h};
		}

		printf("i: %d, h1: %d; j: %d, h2: %d; h: %d\n", i, h1, j, h2, h);
		
	}

	// append;
	if (i >= s1->n) {
		// append s2;
		while (j < s2->n) {
			s->strips[s->n++] = s2->strips[j++];
		}
	}
	else {
		while (i < s1->n) {
			s->strips[s->n++] = s1->strips[i++];
		}
	}

	free(s1->strips);
	free(s2->strips);
	free(s1);
	free(s2);

	s->strips = realloc(s->strips, s->n * sizeof(strip_t));

	return s;

}

skyline_t* find_skyline_helper(building_t* buildings, int left, int right) {

	skyline_t* s;
	if (left > right) {
		s = (skyline_t*)calloc(1, sizeof(skyline_t));
		s->n = 0;
		s->strips = NULL;
		return s;
	}
	if (left == right) {
		// single building;
		s = (skyline_t*)calloc(1, sizeof(skyline_t));
		s->n = 2;
		s->strips = (strip_t*)calloc(2, sizeof(strip_t));
		s->strips[0] = (strip_t){buildings[left].left, buildings[left].height};
		s->strips[1] = (strip_t){buildings[left].right, 0};
		return s;
	}

	int mid = (left + right) / 2;
	// printf("left: %d, right: %d, mid: %d\n", left, right, mid);
	skyline_t* s1 = find_skyline_helper(buildings, left, mid);
	skyline_t* s2 = find_skyline_helper(buildings, mid + 1, right);

	int i;
	printf("s1: %d\n", s1->n);
	for (i = 0; i < s1->n; i++) {
		printf("[%d]: left - %d, heigth - %d\n", i + 1, s1->strips[i].left, s1->strips[i].height);
	}
	printf("s2: %d\n", s2->n);
	for (i = 0; i < s2->n; i++) {
		printf("[%d]: left - %d, heigth - %d\n", i + 1, s2->strips[i].left, s2->strips[i].height);
	}

	s = merge_skylines(s1, s2);
	printf("s: %d\n", s->n);
	for (i = 0; i < s->n; i++) {
		printf("[%d]: left - %d, heigth - %d\n", i + 1, s->strips[i].left, s->strips[i].height);
	}
	getchar();

	return s;

}

skyline_t* find_skyline(building_t* buildings, int n) {

	return find_skyline_helper(buildings, 0, n - 1);

}


void test_skyline() {

	building_t* buildings = (building_t*)calloc(8, sizeof(building_t));
	buildings[0] = (building_t){1,  11, 5};
	buildings[1] = (building_t){2,  6,  7};
	buildings[2] = (building_t){3,  13, 9};
	buildings[3] = (building_t){12, 7,  16};
	buildings[4] = (building_t){14, 3,  25};
	buildings[5] = (building_t){19, 18, 22};
	buildings[6] = (building_t){23, 13, 29};
	buildings[7] = (building_t){24, 4,  28};

	skyline_t* s = find_skyline(buildings, 8);
	for (int i = 0; i < s->n; i++) {
		printf("[%d]: left - %d, heigth - %d\n", i + 1, s->strips[i].left, s->strips[i].height);
	}

	free(s->strips);
	free(s);

	free(buildings);

}


int main() {

	test_skyline();

	return 0;

}
