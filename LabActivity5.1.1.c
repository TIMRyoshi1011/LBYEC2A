/*
Lab Activity Number	: 5.1
Lab Activity Title	: Looping Statements

Date Performed		: May 31, 2024
Date Submitted		: May 31, 2024

Machine Problem:
Design and implement a program that will find the result of the following:

Summation of 2i + 5, where i is an integer from 53 to 15674.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int sum, i;

    for(i=53; i<=15674; i++)
    {
        sum = (2*i) + 5;
    }

    printf("The sum is %d", sum);
    getch();
    return 0;
}

