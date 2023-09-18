//
// Created by Abhinav Kayastha on 18/09/2023.
//

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int count_words(const char* str, char *word)
{
    int count= 0;
    char *position = (char *)str;

    while ((position = strstr(position, word)) != NULL) {
        count++;
        position += strlen(word);
    }

    return count;
}

int main()
{
    char long_sentence[1000];
    char word[1000];

    while (1)
    {
        printf("\nEnter a sentence, or 'stop' to quit: ");
        fgets(long_sentence, sizeof(long_sentence), stdin);

        long_sentence[strcspn(long_sentence, "\n")] = '\0';

        if (strcmp(long_sentence, "stop") == 0)
        {
            break;
        }

        printf("\nEnter a word to find within the sentence: ");
        fgets(word, sizeof(word), stdin);

        word[strcspn(word, "\n")] = '\0';

        int amount = count_words(long_sentence, word);
        printf("\nThe word '%s' occurs in '%s' %d times.", word, long_sentence, amount);

    }

    return 0;
}