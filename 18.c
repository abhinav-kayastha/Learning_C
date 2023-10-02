//
// Created by Abhinav Kayastha on 02/10/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
    while (1)
    {
        srand(time(NULL));

        int num;
        int random_num = rand() % 16;
        int hex_num;

        printf("\nEnter a number between 0-15, or negative number to quit: ");
        scanf("%d", &num);

        if (num < 0 || num > 15)
        {
            break;
        }

        else
        {
            printf("%d in Hexadecimal form is: %X\n", num, num);
        }
    }

    return 0;
}