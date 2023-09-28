#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node {
    int number;
    struct node* next;
} nnode;

int main() {
    nnode* head = NULL;

    while (1) {
        char input[50];
        printf("Enter a number (or 'end' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "end") == 0) {
            break;
        } else {
            int num;
            if (sscanf(input, "%d", &num) == 1) {
                nnode* new_node = (nnode*)malloc(sizeof(nnode));
                if (new_node == NULL) {
                    fprintf(stderr, "Memory allocation failure.");
                    return 1;
                }

                new_node->number = num;
                new_node->next = NULL;

                if (head == NULL) {
                    head = new_node;
                } else {
                    nnode* current = head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = new_node;
                }
            } else {
                fprintf(stderr, "Invalid input. Please enter a number.\n");
                while ((getchar()) != '\n');
            }
        }
    }

    printf("Entered numbers:\n");
    nnode* current = head;
    while (current != NULL) {
        printf("%d\n", current->number);
        nnode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
