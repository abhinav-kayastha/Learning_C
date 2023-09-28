//
// Created by Abhinav Kayastha on 25/09/2023.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define LINESIZE 80
#define MENU_SIZE 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main()
{
    FILE *my_file;
    char file_name[50];
    char line[LINESIZE];
    int lc = 0;
    menu_item menu_items[MENU_SIZE];

    printf("Enter the file to read from: ");
    fgets(file_name, LINESIZE, stdin);
    file_name[strcspn(file_name, "\n")] = 0;

    my_file = fopen(file_name, "r");

    if (my_file == NULL)
    {
        fprintf(stderr, "Unable to open the file to read from.");
        return 1;
    }

    else
    {
        while (lc < MENU_SIZE && fgets(line, sizeof(line), my_file) != NULL)
        {
            sscanf(line, "%49[^;]; %lf", menu_items[lc].name, &menu_items[lc].price);
            lc++;
        }
        fclose(my_file);
    }

    printf("Menu      Price\n");

    for (int i = 0; i < lc; i++)
    {
        printf("%-10s %-8.2lf\n", menu_items[i].name, menu_items[i].price);
    }

    return 0;
}