//
// Created by Abhinav Kayastha on 28/08/2023.
//

#include <stdio.h>

int read_integer(void)
{
    float num;
    printf("\nEnter a positive integer or negative number to quit: ");

    if (scanf("%f", &num) != 1)
    {
        while(getchar() != '\n');
        printf("Incorrect input.");
    }

    return num;
}

int main()
{
    float count = 0;
    float sum = 0;
    float avg;

    while (1)
    {
        float num = read_integer();

        if (num < 0)
        {
            break;
        }

        else
        {
            count += 1;
            sum += num;
        }
    }

    avg = sum/count;

    printf("\nYou entered %.f positive numbers. The average is: %.2f", count, avg);

    return 0;
}