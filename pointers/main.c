#include <stdio.h>

int main() {
    int a = 5;

    int *a_ptr = &a;

    a++;

    printf("a: %d\n", a);
    printf("a pointer: %d\n", *a_ptr);

    int b = 3;

    int b_copy = b;

    b++;

    printf("b: %d\n", b);
    printf("b copy: %d\n", b_copy);

    return 0;
}
