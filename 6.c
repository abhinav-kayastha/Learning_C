//
// Created by Abhinav Kayastha on 29/08/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rolld6()
{
    int value = rand() % 6 + 1;

    printf("\nYour roll is with a D6 is: %d\n", value);
}

void rolld10()
{
    int value = rand() % 10 + 1;

    printf("\nYour roll is with a D10 is: %d\n", value);
}

int main()
{
    srand(time(NULL));

    while (1)
    {
        int choice = 0;
        printf("- Roll D6 (6)\n- Roll D10 (10)\n- Quit (-1)\nSelect Operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 6:
                rolld6();
                continue;

            case 10:
                rolld10();
                continue;

            case -1:
                printf("\nThank you for playing.");
                return 0;

            default:
                printf("\nPlease enter a valid input.\n");
        }
    }
}