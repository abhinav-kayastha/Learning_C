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

    printf("Enter your tax percentage applied to income over the limit: ");
    scanf("%f", &greater_tax_percentage);

    for (int i = 0; i < 12; i++)
    {
        printf("\nEnter salary for month %d: ", i + 1);
        scanf("%f", &salary[i]);
        salary_sum += salary[i];

        if (salary_sum > yearly_limit_salary)
        {
            tax_salary[i] = (greater_tax_percentage / 100) * salary[i];
        }

        else
        {
            tax_salary[i] = (tax_percentage / 100) * salary[i];
        }

        printf("\nSalary of month %d: %.2f: ", i + 1, salary[i]);
        printf("\nTaxed income of month %d: %.2f\n", i + 1, tax_salary[i]);
    }

    printf("month\tincome\ttax");

    return 0;
}