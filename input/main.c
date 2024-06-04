#include <stdio.h>

int main() {
    printf("What is your name and age: ");

    char name[30];
    int age;

    scanf("%29s %d", name, &age);

    printf("Hello %s!\n", name);
    printf("You are %d years old.\n", age);

    return 0;
}
