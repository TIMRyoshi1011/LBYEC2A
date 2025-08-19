/*
Lab Activity Number	: 5.1
Lab Activity Title	: Looping Statements

Date Performed		: May 31, 2024
Date Submitted		: May 31, 2024

Machine Problem:
Combine Exercises A and B using switch/case statement. Case 1 for Exercise A, Case 2 for Exercise B and Case 3 for Exit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int one(int i);
int two(int num2);

int main(int argc, char *argv[])
{
    int option, no = 0, num;

    do {
    printf("Enter Option:\n");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
        printf("The sum is %d\n", one(no));
        break;

        case 2:
        printf("Enter a number:\n");
        scanf("%d", &num);
        printf("\nThe sum is: %d\n", two(num));
        break;

        case 3:
        printf("Thank you!\n");
        break;

        default:
        printf("Invalid Option, Please Try Again\n");
    }   

    } while (option != 3);

    getch();
    return 0;
}

int one(int i)
{
    int sum;
    for(i=53; i<=15674; i++)
    {
        sum = (2*i) + 5;
    }

    return sum;
}

int two(int num2)
{
    int sum3, no2;
    sum3 = 0;

    for(no2=1; no2<=num2; no2++)
    {
        sum3 += no2;
    }

    return sum3;
}