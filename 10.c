//
// Created by Abhinav Kayastha on 14/09/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    while (1)
    {
        char string[50];
        printf("\nEnter a max 50 character string, type stop to end: ");
        fgets(string, 50, stdin);
        string[strlen(string) - 1] = '\0';

        if (!strcmp("stop", string))
        {
            printf("\nExiting program.");
            break;
        }

        printf("The string's length is %zu", strlen(string));
    }


    return 0;
}