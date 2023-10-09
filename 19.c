//
// Created by Abhinav Kayastha on 05/10/2023.
//

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

int getMenuSortingChoice()
{
    int choice;
    printf("Choose sorting order:\n");
    printf("1. Sort by name\n");
    printf("2. Sort by price\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    return choice;
}

int sortByName(const void *item1, const void *item2)
{
    return strcmp(((menu_item*)item1)->name, ((menu_item*)item2)->name);
}

int sortByPrice(const void *item1, const void *item2)
{
    return (*(menu_item*)item1).price - (*(menu_item*)item2).price;
}

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

    int choice = getMenuSortingChoice();

    if (choice == 1)
    {
        qsort(menu_items, lc, sizeof(menu_item), sortByName);
    }

    else if (choice == 2)
    {
        qsort(menu_items, lc, sizeof(menu_item), sortByPrice);
    }

    else
    {
        printf("Invalid choice.");
    }

    for (int i = 0; i < lc; i++)
    {
        printf("%-10s %-8.2lf\n", menu_items[i].name, menu_items[i].price);
    }

    return 0;
}