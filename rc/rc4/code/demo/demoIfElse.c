#include <stdio.h>


void logicalEval() {

	int a;

    scanf("%d", &a);
    if (0 <= a <= 2) {
        printf("a = %d\n", a);
    }

}

void blocksExec() {

	if (0)
		printf("1\n");
		printf("2\n");

}


int main() {

	// logicalEval();
	blocksExec();

    return 0;

}