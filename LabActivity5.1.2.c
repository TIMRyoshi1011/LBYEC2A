/*
Lab Activity Number	: 5.1
Lab Activity Title	: Looping Statements

Date Performed		: May 31, 2024
Date Submitted		: May 31, 2024

Machine Problem:
Write a program that accepts a single positive integer. The program should output the value of the summation. This means that if the input is 5, 
the program should output the sum of all numbers from 1 to 5, or 15. If the input is 10, the program should output the sum of all numbers of 1 to 10, or 55.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int num, no1, sum2;
    printf("Enter a number:\n");
    scanf("%d", &num);

    sum2 = 0;

    for(no1=1; no1<=num; no1++)
    {
        sum2 += no1;
    }
    printf("\nThe sum is: %d", sum2);
    getch();
    return 0;
}