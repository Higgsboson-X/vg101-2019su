#include <stdio.h>
// a: pass by address;
// size: pass by value;
void set_array(int a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i] = i + 1;
	}
    // will not affect the value of size;
    size = 7;
}

int main() {

    int a[10] = {0};
    int size = 10;
    set_array(a, size);
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    printf("%d\n", size);

	return 0;
	
}