#include <stdio.h>
#include <string.h>

int main() {
    char s1[10] = {0};
    char s2[] = "memset is useful";
    
    memset(s1, '-', 9);
    memset(s2 + 7, '=', 2);

	printf("%d\n", s1[9] == '\0');
    
    puts(s1);
    puts(s2);

	char str[20];
	memset(str, 'a', 20 * sizeof(char));

	// str[19] = '\0';

	printf("%d %d\n", sizeof(unsigned char), sizeof(int));

	puts(str);
	
    return 0;

}