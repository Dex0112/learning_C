#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y) {
    if (x == 1) {
        return y;
    }

    if (x == 0) {
        return 0;
    }

    return y + multiply(x - 1, y);

}

int main() {
    printf("%d\n", multiply(5, 5));

    return 0;
}
