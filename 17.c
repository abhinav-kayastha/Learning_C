//
// Created by Abhinav Kayastha on 02/10/2023.
//

#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

bool pass_gen(char *password, int size, const char *word)
{
    srand(time(NULL));

    int pass_len = strlen(word) * 2 + 1;

    if (pass_len > size)
    {
        return false;
    }

    for (int i = 1; i <= pass_len; i++)
    {
        if (i % 2 == 0)
        {
            password[i - 1] = word[i/2 - 1];
        }

        else
        {
            char random_char;

            do
            {
                random_char = rand() % 255;
            }
            while (!isprint(random_char));
            password[i - 1] = random_char;
        }
    }

    password[pass_len] = '\0';

    return true;
}

int main()
{
    char password[32];
    char word[32];

    while (1)
    {
        char choice[20];

        printf("\nEnter a word to place in password, type 'stop' to end: ");
        scanf("%s", choice);

        if (strcmp(choice, "stop") == 0)
        {
            break;
        }

        else
        {
            strncpy(word, choice, sizeof(word));
            word[sizeof(word) - 1] = '\0';

            if (pass_gen(password, sizeof(password), word))
            {
                printf("\nPassword: %s", password);
            }

            else
            {
                printf("\nError in password generation.");
            }
        }
    }

    return 0;
}