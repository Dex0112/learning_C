#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int age;
} person;

int main() {
    person * myperson = (person *) malloc(sizeof(person));

    myperson->name = "Landon";
    myperson->age = 18;

    printf("Name: %s\nAge: %d", myperson->name, myperson->age);

    free(myperson);

    return 0;
}
