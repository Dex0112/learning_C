#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testRandomDistrobution(unsigned int min, unsigned int max,
                            unsigned int sampleSize);

int main() {
    srandom(time(NULL));

    printf("Select 1 (play) 2 (run test): ");

    int choice;

    scanf("%d", &choice);

    if (choice == 2) {

        unsigned int min;
        unsigned int max;
        unsigned int sampleSize;

        printf("Min Max SampleSize: ");
        scanf("%d %d %d", &min, &max, &sampleSize);

        testRandomDistrobution(min, max, sampleSize);

        return 0;
    }

    while (1) {
        int userPick;
        printf("Pick a random number between 1-10: ");
        scanf("%d", &userPick);

        int randomPick = random() % 10 + 1; // Random Number

        if (userPick > 10 || userPick < 1) {
            printf("ERROR: You have input an invalid number!\n");
            return 1;
        }

        if (userPick == randomPick) {
            printf("We picked the same random number!\n");
            return 0;
        }

        printf(
            "We picked different numbers ;(\nI picked %d and you picked %d\n",
            randomPick, userPick);
    }

    return 0;
}

void testRandomDistrobution(unsigned int min, unsigned int max,
                            unsigned int sampleSize) {
    printf("Sample Size: %d\nMin: %d\nMax: %d\n", sampleSize, min, max);

    int errors = 0;
    int occurances[max - min + 1];

    for (int i = 0; i < max - min + 1; i++) {
        occurances[i] = 0;
    }

    for (int i = 0; i < sampleSize; i++) {
        int rNum = min + (random() % (max - min + 1));

        if (rNum < min || rNum > max) {
            printf("ERROR: random number is out of range!\nExpected %d-%d and "
                   "got %d!\n",
                   min, max, rNum);
            errors++;
            continue;
        }

        int idx = rNum - min;

        occurances[idx]++;
    }

    // Find distrobutions
    float totalPercent = 0;

    for (int i = 0; i < max - min + 1; i++) {
        int occuranceCount = occurances[i];
        int num = i + min;
        float distrobution = (float)occuranceCount / sampleSize;

        totalPercent += distrobution;

        printf("%d (%d): %.2f%%\n", num, occurances[i], distrobution * 100.0);
    }

    printf("Percent Total %.2f%%\n", totalPercent * 100.0);

    float errorRate = (float)errors / sampleSize;
    printf("Error Rate: %.2f%%\n", errorRate * 100.0);
}
