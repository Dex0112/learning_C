#include <stdio.h>

int main() {
    int num1;
    int num2;

    printf("Enter 2 numbers for int division: ");

    scanf("%d %d", &num1, &num2);

    if (num2 == 0) {
        printf("ERROR: Second number was 0");
        return 1;    
    }

    int quotient = num1 / num2;

    printf("Int division:\n");
    printf("%d / %d = %d\n", num1, num2, quotient);

    return 0;
}
