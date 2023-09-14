//
// Created by Abhinav Kayastha on 14/09/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int replace_char(char *str, const char *repl)
{
    int replaced = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == repl[0])
        {
            str[i] = repl[1];
            replaced++;
        }
    }

    if (replaced == 0 && strlen(repl) != 2)
    {
        return 0;
    }

    return replaced;
}

int main()
{
    char two_string[3];
    printf("Enter a two character string: ");
    scanf("%2s", &two_string);
    clearInputBuffer();

    if (strlen(two_string) != 2)
    {
        printf("String does have 2 characters, re-run the program.");
        exit(1);
    }

    char modify_string[50];
    printf("\nEnter a max 50 character string to be modified: ");
    fgets(modify_string, 50, stdin);

    if (strlen(modify_string) >= 50)
    {
        printf("\nString exceeds 50 characters, re-run the program.");
        clearInputBuffer();
        exit(1);
    }

    int changes = replace_char(modify_string, two_string);

    if (changes == 0)
    {
        printf("String was not modified.");
    }

    else
    {
        printf("\nProgram made %d change(s), and here is the modified string: %s", changes, modify_string);
    }

    return 0;
}