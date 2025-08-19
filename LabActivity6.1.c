/*
Lab Activity Number	: 6.1
Lab Activity Title	: Arrays

Date Performed		: July 9, 2024
Date Submitted		: July 9, 2024

Machine Problem:
Write a program that determines the sum and the lowest of the 15 input values.
Sample:
Enter 15 values:
12 10 15 21 25 28 51 24 2 5 9 78 98 52 41
The sum is: 471
The lowest value: 2
*/

#include <stdio.h>

main()
{
    int n[15];
    int low, i, sum;

    sum = 0;

    printf("Enter 15 Numbers:\n");
    for(i=0; i<15; i++)
    {
        scanf("%d",&n[i]);
        sum += n[i];

        if (i == 0 || n[i] < low)
        {
            low = n[i];
        }
    }

    printf("The sum is: %d\n", sum);
    printf("The lowest number is: %d\n", low);

    getch();
    return 0;
}