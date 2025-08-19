/*
Lab Activity Number	: 4.1
Lab Activity Title	: Functions Part 1

Date Performed		: May 24, 2024
Date Submitted		: May 24, 2024

Machine Problem:
An employee is paid on an hourly basis. Write a C-language program that accepts an employee’s ID number, his rate per hour and the number of hours worked for 2 weeks 
then outputs his gross pay, total deductions, and net pay. Use float as datatype.
Use the following formula:
GROSS PAY (2 weeks) = rate per hour* no. of hours worked
(note: an employee can work for maximum of 8 hrs per day only)
DEDUCTIONS:
Tax deduction using Function pass-by-value
if Gross pay:
<= 10000: 10%
10001 to 20000: 12%
20001 to 30000: 15%
> 30000: 17%
 
SSS = 900
PHILHEALTH = 150
PAG IBIG = 150

TOTAL DEDUCTIONS = tax + sss + philhealth + pagibig
NET PAY = gross pay – total deductions
*/

#include <stdio.h>
#include <stdlib.h>
#define sss 900
#define philhealth 150
#define pagibig 150

float pay(float gross);

int main(int argc, char *argv[])
{
    float idno, rate, hours, gross, tax, deductions, net;

    printf("Enter Employee's ID Number: \n");
    scanf("%f", &idno);

    printf("Enter Rate per Hour: \n");
    scanf("%f", &rate);

    printf("Enter Number of Hours worked for 2 weeks: \n");
    scanf("%f", &hours);

    if ((hours<=80) && (hours>=0))
    {
        gross = rate * hours;
        deductions = sss + philhealth + pagibig + pay(gross);
        net = gross - deductions;
        printf("\nEmployee ID: %.0f", idno);
        printf("\nGross Pay: %.2f", gross);
        printf("\nTotal Deductions: %.2f", deductions);
        printf("\nNet Pay: %.2f\n", net);
    }

    else if (hours>80)
    printf("\nExceeded the maximum number of hours\n");

    else
    printf("\nInvalid Number\n");

    system("PAUSE");
    return 0;
}

float pay(float gross)
{
    float tax;

        if (gross<=10000)
        tax = 0.10 * gross;
            
        else if ((gross>=10001) && (gross<=20000))
        tax = 0.12 * gross;
            
        else if ((gross>=20001) && (gross<=30000))
        tax = 0.15 * gross;
            
        else if (gross>30000)
        tax = 0.17 * gross;
            
        else
        printf("Syntax Error!\n");

    return tax;
}
