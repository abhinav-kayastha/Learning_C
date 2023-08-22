//
// Created by Abhinav Kayastha on 22/08/2023.
//

#include <stdio.h>

int main()
{
    float salary[12];
    float tax_salary[12];
    float tax_percentage;
    float greater_tax_percentage;
    float yearly_limit_salary;
    float salary_sum = 0;

    printf("Enter your tax percentage: ");
    scanf("%f", &tax_percentage);

    printf("Enter your yearly salary limit: ");
    scanf("%f", &yearly_limit_salary);

    printf("Enter your tax percentage in the applied to income over the limit: ");
    scanf("%f", &greater_tax_percentage);

    for (int i = 0; i < 12; i++)
    {
        printf("Enter salary for month %d: ", i);
        scanf("%f", &salary[i]);
        salary_sum += salary[i];

        if (salary_sum > yearly_limit_salary)
        {
            tax_salary[i] = greater_tax_percentage * salary[i];
        }

        else
        {
            tax_salary[i] = tax_percentage * salary[i];
        }

        printf("Salary of month %d: ", salary[i]);
        printf("Taxed income of month %d: ", tax_salary[i]);
    }

    return 0;
}