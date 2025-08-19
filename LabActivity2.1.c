/*
Lab Activity Number	: 2.1
Lab Activity Title	: Employee’s Payslip

Date Performed		: May 10, 2024
Date Submitted		: May 10, 2024

Machine Problem:
An employee is paid on an hourly basis. Write a C-language program that accepts the employee’s ID number, his rate per hour and the number of hours worked for 2 weeks 
then outputs his gross pay, total deductions, and net pay. Use float as datatype.
Use the following formula:

Gross pay (2 weeks) = rate per hour* no. of hours worked
Deductions:
Tax = 20% of gross pay
SSS = 5% of gross pay
Philhealth = 150
Pag-ibig = 150
Total deductions = tax + sss + philhealth + pagibig
Net pay = gross pay – total deductions
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define philhealth 150
#define pagibig 150

int main() 
{
    float idno, rate, noofhours, gross, tax, sss, deductions, net;

    printf("\nEnter employee's ID number: ");
    scanf("%f", &idno);

    printf("\nEnter rate per hour: ");
    scanf("%f", &rate);

    printf("\nEnter number of hours worked for 2 weeks: ");
    scanf("%f", &noofhours);

    gross = rate * noofhours;
    tax = gross*0.20;
    sss = gross*0.05;
    deductions = tax + sss + philhealth + pagibig; 
    net = gross - deductions;

    printf("\nEmployee ID: %f", idno);
    printf("\nGross Pay: %f", gross);
    printf("\nTotal Deductions: %f", deductions);
    printf("\nNet Pay: %f", net);

    system("PAUSE");
    return 0;
}