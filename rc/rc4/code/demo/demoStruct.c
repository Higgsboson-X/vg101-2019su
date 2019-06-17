#include <stdio.h>

typedef struct Person {

	char* name;
	int age;

} person_t;

int main() {

	person_t p;

	printf("%s %d\n", p.name, p.age);

	return 0;

}
