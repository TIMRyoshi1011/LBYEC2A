/*
Lab Activity Number	: 5.2
Lab Activity Title	: Looping Statements (Assignment)

Date Performed		: June 06, 2024
Date Submitted		: June 06, 2024

Machine Problem:
Mr. Armstrong
C programming code to check whether a number is an Armstrong number or not. An Armstrong number is a number which is equal to the sum of digits raise 
to the power of the total number of digits in the number. Some Armstrong numbers are: 0, 1, 2, 3, 153, 370, 407, 1634, 8208, etc.
The algorithm to do this is: First we calculate the number of digits in our program and then compute the sum of individual digits raise to the power number of digits. 
If this sum equals the input number, then the number is an Armstrong number otherwise not.
Examples:
7 = 7^1
371 = 3^3 + 7^3 + 1^3 (27 + 343 +1)
8208 = 8^4 + 2^4 +0^4 + 8^4 (4096 + 16 + 0 + 4096).
 
Sample Input:
371
 
Sample Output:
Total number of digits= 3
3^3= 27
7^3= 343
1^3= 1
Sum= 371
 
ARMSTRONG NUMBER!
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int no, no2, no3, a;

    printf("Enter a number:\n");
    scanf("%d", &no);

    a = no;

    while(no > 0)
    {
        no2 = no % 10;
        no3 = no3 + no2 * no2 * no2;
        no = no / 10;
    }

    if (a == no3)
    printf("\nARMSTRONG NUMBER!");

    else
    printf("\nNOT ARMSTRONG NUMBER!");

    getch();
    return 0;
}