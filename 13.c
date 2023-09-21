//
// Created by Abhinav Kayastha on 21/09/2023.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define LINESIZE 80

int main()
{
    char filename[50];
    char line[LINESIZE];
    int count = 0;
    int value;
    int highest;
    int lowest;

    printf("Enter a file name: ");
    fgets(filename, LINESIZE, stdin);

    filename[strcspn(filename, "\n")] = 0;

    FILE *user_file;

    user_file = fopen(filename, "r");

    if(user_file == NULL) {
        fprintf(stderr, "File was not opened.\n");
    }
    else {
        printf("File was opened.\n");
        while (!feof(user_file)) {
            if (fgets(line, LINESIZE, user_file) != NULL) {
                if (sscanf(line, "%d", &value) == 1) {
                    count++;
                    if (value > highest) {
                        highest = value;
                    }
                    if (value < lowest) {
                        lowest = value;
                    }
                }
            }
        }
        printf("Amount of numbers: %d\n", count);
        printf("Highest number: %d\n", highest);
        printf("Lowest number: %d\n", lowest);
        fclose(user_file);
    }

    return 0;
}