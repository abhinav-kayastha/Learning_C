#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value)
{
    int num;

    printf("Enter a positive number: ");

    if (scanf("%d", &num) == 0)
    {
        return false;
    }

    if (num > 0)
    {
        *value = num;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int num;
    int value;
    int count = 0;

    printf("Guess how much money I have!\n");

    while (count < 3)
    {
        if (read_positive(&num))
        {
            value = num * 2 + 20;

            printf("Incorrect. The correct amount is %d euros. You guessed %d euros.\n", value, num);
        }
        else
        {
            printf("\nIncorrect input.\n");
            count++;
        }
    }

    printf("You have failed me. :(");

    return 0;
}
