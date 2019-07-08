#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE* fp = fopen("fileIn.txt", "r");

	char buffer[20] = {0};
	// scan everything in string format;
	while (fscanf(fp, "%s", buffer) != EOF) {
		printf("%s %ld\n", buffer, strlen(buffer));
	}

	// return to beginning of file;
	rewind(fp);
	int a, b;
	// read two integers;
	fscanf(fp, "%d %d\n", &a, &b);
	puts("-------");
	printf("a = %d, b = %d\n", a, b);
	
	// read the following content, store in s;
	char s[100] = {0};
	int k = 0;
	puts("-------");
	while (fgets(buffer, 20, fp)) {
		printf("%s%ld, pos %ld\n", buffer, strlen(buffer), ftell(fp));
		strcpy(s + k, buffer);
		k = strlen(s);
	}
	// get rid of the last '\n';
	s[k - 1] = '\0';
	puts("-------");
	puts(s);
	
	fclose(fp);

	fp = fopen("fileOut.txt", "w");
	fputs(s, fp);
	fclose(fp);

	return 0;

}
