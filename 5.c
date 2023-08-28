//
// Created by Abhinav Kayastha on 28/08/2023.
//

#include <stdio.h>

int read_range(int low, int high)
{
    int num;

    printf(" Roll a die and enter your result.");
    printf("\nEnter a number between 1 and 6: ");
    scanf("%d", &num);

    while (1)
    {
        if (num < low || num > high)
        {
            printf("Invalid input.");
            printf("\nEnter a number between 1 and 6: ");
            scanf("%d", &num);
        }

        else
        {
            break;
        }
    }

    return num;
}

int main()
{
    int user_num;
    int program_num;

    printf("\nLet's play!");

    for (int i = 0; i < 3; i++)
    {
       user_num = read_range(1, 6);

       if (user_num == 6)
       {
           program_num = 6;
           printf("\nI got 6. It's a tie.");
           continue;
       }

       program_num = user_num + 1;

        printf("\nI got %d. I win!", program_num);
    }

    printf("\nBetter luck next time. Bye!");

    return 0;
}