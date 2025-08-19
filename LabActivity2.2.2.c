/*
Lab Activity Number	: 2.2
Lab Activity Title	: C-Language: Basic I/O

Date Performed		: May 16, 2024
Date Submitted		: May 17, 2024

Machine Problem:
Create a program that will compute your grade. Use LBYEC2A Grading system.
Lab Activities: 40%
Project: 30%
Practical Exam 1: 15%
Practical Exam 2: 15%
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float labact, project, pe1, pe2, final;

    printf("\nEnter Lab Activities Grade: ");
    scanf("%f", &labact);

    printf("\nEnter Project Grade: ");
    scanf("%f", &project);

    printf("\nEnter Practical Exam 1 Grade: ");
    scanf("%f", &pe1);

    printf("\nEnter Practical Exam 2 Grade: ");
    scanf("%f", &pe2);

    final = (labact * 0.4) + (project * 0.3) + (pe1 * 0.15) + (pe2 * 0.15);

    printf("\nFinal Grade = %.2f", final);

     system("PAUSE");
     return 0;
}