#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int random_val(int range[4][2], int modulus);

int main(void) {
    srand(time(0));

    int spec_chars_min = 33;
    int spec_chars_max = 47;

    int nums_min = 48;
    int nums_max = 57;

    int caps_min = 65;
    int caps_max = 90;

    int lows_min = 97;
    int lows_max = 122;

    int caps_range[2] = { caps_min, caps_max };
    int lows_range[2] = { lows_min, lows_max };
    int nums_range[2] = { nums_min, nums_max };
    int spec_range[2] = { spec_chars_min, spec_chars_max };

    int ranges[4][2] = { *caps_range, *lows_range, *nums_range, *spec_range };

    int q1;
    int q2;
    int q3;
    int q4; 
    int q5;
    int q6;

    printf("Welcome to the password generator. Press 1 to start, or 2 to quit: ");
    scanf("%i", &q1);

    while (q1 > 2 || q1 < 1) {
        printf("Only type 1 or 2. Press 1 to start, or 2 to quit: ");
        scanf("%i", &q1);
    }

    if (q1 == 2) {
        printf("Bye!\n");
        return 0;
    } else if (q1 == 1) {
        printf("Awesome, let's get started.\nA) What is the length of the password? Enter an integer: ");
        scanf("%i", &q2);

        while (q2 < 8) {
            printf("\nMust be an integer of at least 8 or more: ");
            scanf("%i", &q2);
        }

        printf("\nB) Do you want uppercase letters? 1 for yes, 2 for no: ");
        scanf("%i", &q3);

        while (q3 > 2 || q3 < 1) {
            printf("\nResponse not in range; 1 for yes, 2 for no: ");
            scanf("%i", &q3);
        }

        printf("\nC) Do you want lowercase letters? 1 for yes, 2 for no: ");
        scanf("%i", &q4);

        while (q4 > 2 || q4 < 1) {
            printf("\nResponse not in range; 1 for yes, 2 for no: ");
            scanf("%i", &q4);
        }

        printf("\nD) Do you want numbers? 1 for yes, 2 for no: ");
        scanf("%i", &q5);

        while (q5 > 2 || q5 < 1) {
            printf("\nResponse not in range; 1 for yes, 2 for no: ");
            scanf("%i", &q5);
        }

        printf("\nE) Do you want special characters? 1 for yes, 2 for no: ");
        scanf("%i", &q6);

        while (q6 > 2 || q6 < 1) {
            printf("\nResponse not in range; 1 for yes, 2 for no: ");
            scanf("%i", &q6);
        }
    }

    int responses[4] = { q3, q4, q5, q6 };
    char password[q2+1];

    for (int i = 0; i < q2; i++) {
        int modulus = i % 4;
        if (responses[modulus] == 1) {
            password[i] = random_val(&ranges[4][2], modulus);
            printf("ASCII = %i || Char = %c\n", password[i], password[i]);
        } else if (responses[modulus] == 2) {
            password[i] = random_val(&ranges[4][2], (modulus+1));
        }
    }
    
    printf("\nYour password is: %s\n\n", password);

    return 0;
}

int random_val(int range[4][2], int iter) {
    int min = range[iter][0];
    int max = range[iter][1];
    int rand_num = min + rand()%(max-min+1);
    printf("\nrandom number = %i || min = %i || max = %i\n", rand_num, min, max);

    return rand_num;
}