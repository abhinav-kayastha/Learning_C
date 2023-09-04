//
// Created by Abhinav Kayastha on 04/09/2023.
//

#include "stdio.h"
#include <stdlib.h>
#include <time.h>

void print_numbers (const int *array, int count)
{

    for (int i = 0; i < count; i++)
    {
        printf("%8d\n", array[i]);
    }
}

int main()
{
    srand(time(NULL));

    int nums[15];

    print_numbers(nums, 15);
}