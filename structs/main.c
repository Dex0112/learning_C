#include <stdio.h>

struct point {
    int x;
    int y;
};

typedef struct {
    int x;
    int y;
} point_typedef;

int main() { 
    point_typedef p1 = {
        .x = 1,
        .y = 1,
    };

    struct point p = {
        .x = 0,
        .y = 0,
    };

    printf("Struct\nX: %d\nY: %d\n", p.x, p.y);
    printf("Typedef\nX: %d\nY: %d\n", p1.x, p1.y);

    return 0; 
}
