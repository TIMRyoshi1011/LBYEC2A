/*
Lab Activity Number	: 2.2
Lab Activity Title	: C-Language: Basic I/O

Date Performed		: May 16, 2024
Date Submitted		: May 17, 2024

Machine Problem:
Design then implement a program that determines the day of the week (Sunday through Saturday) given any date entered by the user (or initialized to the variables). 
You could use this program, for example, to determine what day of the week you were born on or what day of the week an upcoming exam is on given its date. 
Use Zeller’s congruence algorithm to calculate the day of the week.

Where:
d is the calculated day of the week (0..6) day is the day entered by the user.
m is the adjusted month (January and February are 13 and 14, not 1
and 2)
y is the last two digits of the adjusted year (January and February are in the previous year). For example: if year is 2003, then y would be 03
c is the century of the adjusted year (January and February are in the previous year). For example, if year is 2003, then c is 20
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int month, day, y, c, d;

    printf("Enter Month: ");
    scanf("%2d", &month);

    printf("Enter Day: ");
    scanf("%2d", &day);

    printf("Enter Year: ");
    scanf("%2d%2d", &c, &y);

    d = (day + ((26 * (month + 1)) / 10) + y + (y / 4) + (c / 4) + 5 * c) % 7;

    if(d == 0)
    {
        printf("\nMonday\n\n");
    }

    else if(d == 1)
    {
        printf("\nTuesday\n\n");
    }

    else if(d == 2)
    {
        printf("\nWednesday\n\n");
    }

    else if(d == 3)
    {
        printf("\nThursday\n\n");
    }

    else if(d == 4)
    {
        printf("\nFriday\n\n");
    }

    else if(d == 5)
    {
        printf("\nSaturday\n\n");
    }

    else if(d == 7)
    {
        printf("\nSunday\n\n");
    }

        system("PAUSE");
        return 0;
}
