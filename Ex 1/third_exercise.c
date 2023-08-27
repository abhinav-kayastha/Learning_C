#include <stdio.h>

int main()
{
    int student_amount;

    printf("Enter the number of students: ");
    scanf("%d", &student_amount);

    int student[student_amount];

    for (int i = 0; i < student_amount; i++)
    {
        student[i] = -1;
    }

    while (1)
    {
        int student_choice;
        int student_grade;

        printf("Enter student number (1 - %d) or 0 to stop: ", student_amount);
        scanf("%d", &student_choice);

        switch (student_choice)
        {
        case 0:
            printf("Exiting student information input.\n");
            printf("Student\tGrade\n");
            for (int i = 0; i < student_amount; i++)
            {
                printf("%d\t", i + 1);
                if (student[i] == -1)
                {
                    printf("N/A\n");
                }
                else
                {
                    printf("%d\n", student[i]);
                }
            }
            break;
        
        default:
            if (student_choice < 1 || student_choice > student_amount)
            {
                printf("Invalid student number. Try again.\n");
            }
            else
            {
                printf("Enter the grade for student %d (0 - 5 or -1 to cancel): ", student_choice);
                scanf("%d", &student_grade);
                if (student_grade >= -1 && student_grade <= 5)
                {
                    student[student_choice - 1] = student_grade;
                }
                else
                {
                    printf("Invalid grade. Please enter a grade between 0 and 5 or -1.\n");
                }
            }
            break;
        }
    }
    
    return 0;
}
