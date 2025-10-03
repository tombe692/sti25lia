
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, svar;

    // Starta slumpgeneratorn med tiden
    srand(time(0));

    // Generera två slumpmässiga tal mellan 0 och 100
    a = rand() % 101; // 0 till 100
    b = rand() % 101; // 0 till 100

    // Fråga tills användaren svarar rätt
    do {
        printf("How much is %d plus %d? Answer = ", a, b);
        scanf("%d", &svar);

        if (svar == a + b) {
            printf("Very good!\n");
        } else {
            printf("No. Please try again.\n");
        }

    } while (svar != a + b);

    return 0;
} 
