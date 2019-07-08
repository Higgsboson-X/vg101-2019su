#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* sf = fopen("sentence.txt", "r");
	FILE* wf = fopen("word.txt", "r");

	char s[1000] = "";
	fgets(s, 1000, sf);
	char w[10] = "";
	fgets(w, 10, wf);

	fclose(sf);
	fclose(wf);

	printf("%s\n%s\n", s, w);

	return 0;

}