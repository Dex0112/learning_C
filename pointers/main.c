#include <stdio.h>

int main() {
    int a = 5;

    int * pointer_to_a = &a;

    a++;

    printf("a: %d\n", a);
    printf("a pointer: %d\n", *pointer_to_a);

    int b = 3;

    int b_copy = b;

    b++;

    printf("b: %d\n", b);
    printf("b copy: %d\n", b_copy);

    return 0;
}
