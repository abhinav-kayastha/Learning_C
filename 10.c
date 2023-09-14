//
// Created by Abhinav Kayastha on 14/09/2023.
//

#include "stdio.h"
#include "string.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    while (1)
    {
        char string[50];
        printf("\nEnter a max 50 character string, type stop to end: ");
        fgets(string, 50, stdin);
        string[strlen(string) - 1] = '\0';

        if (strlen(string) >= 48)
        {
            printf("\nString exceeds 50 characters, try again.");
            clearInputBuffer();
            continue;
        }

        if (!strcmp("stop", string))
        {
            printf("\nExiting program.");
            break;
        }

        printf("The string's length is %zu", strlen(string));
    }


    return 0;
}