//
// Created by Abhinav Kayastha on 07/09/2023.
//

#include "stdio.h"
#include "stdio.h"
#include "time.h"

int find_first (const unsigned int *array, unsigned int what)
{
    for (int i = 0; i < 20; i++)
    {
        if (array[i] == what)
        {
            return i;
        }

        else if (array[i] == 0)
        {
            return -1;
        }
    }

    return -1;
}

int main ()
{
    srand(time(NULL));
    int num_arr[20];

    for (int i = 0; i < 19; i++)
    {
        num_arr[i] = rand() % 20 + 1;
    }

    num_arr[19] = 0;

    for (int j = 0; j < 20; j++)
    {
        printf("%d\n", num_arr[j]);
    }

    int choice = -1;

    while (choice != 0)
    {
        printf("\nEnter a number (1 - 20) to search, 0 to stop: ");
        if (scanf("%d", &choice) == 0)
        {
            while(getchar() != '\n');
            printf("Incorrect input try again.");
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        int result = find_first(num_arr, choice);

        if (result != -1)
        {
            printf("\nFound %d at index %d.", choice, result);
        }

        else
        {
            printf("\nProgram did not find %d in the array.", choice);
        }
    }
}