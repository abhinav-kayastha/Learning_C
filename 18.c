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
        int random_num = rand();
        int shifted_hex_num;

        printf("\nEnter a number between 0-15, or negative number to quit: ");
        scanf("%d", &num);

        if (num < 0 || num > 15)
        {
            printf("Exiting.");
            break;
        }

        else
        {
            printf("%d in Hexadecimal form is: 0x%X\n", num, num);
            shifted_hex_num = random_num >> num;
            shifted_hex_num = shifted_hex_num & 0x3F;
            printf("The shifted Hexadecimal number is: 0x%X\n", shifted_hex_num);
        }
    }

    return 0;
}