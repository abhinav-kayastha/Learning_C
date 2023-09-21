//
// Created by Abhinav Kayastha on 21/09/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define LINESIZE 80
#define MAXLINE 100

int main()
{
    FILE *my_file;
    FILE *out_file;
    char my_file_name[50];
    char out_file_name[50];
    char line[LINESIZE];
    int lc = 0;

    printf("Enter the file to read from: ");
    fgets(my_file_name, LINESIZE, stdin);
    my_file_name[strcspn(my_file_name, "\n")] = 0;

    printf("Enter the file to write to: ");
    fgets(out_file_name, LINESIZE, stdin);
    out_file_name[strcspn(out_file_name, "\n")] = 0;

    my_file = fopen(my_file_name, "r");
    out_file = fopen(out_file_name, "w");

    if (my_file == NULL)
    {
        fprintf(stderr, "Unable to open the file to read from.");
    }

    else if (out_file == NULL)
    {
        fprintf(stderr, "Unable to open the file to write to.");
    }

    else {
        printf("Reading from %s and writing to %s.\n", my_file_name, out_file_name);
        while(!feof(my_file)) {
            if(fgets(line, LINESIZE, my_file) != NULL) {
                lc++;
                for (int i = 0; i < LINESIZE; i++)
                {
                    line[i] = toupper(line[i]);
                }

                fputs(line, out_file);
            }
        }
        fclose(my_file);
        fclose(out_file);
    }






    return 0;
}