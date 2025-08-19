// Make a program to print the multiplication table of a number entered by the user.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no, i, product;

    printf("Enter a Number:\n");
    scanf("%d", &no);

    for(i=1; i<=10; i++)
    {
        product = no * i;
        printf("\n%d x %d = %d", no, i, product);
    }
    getch();
    return 0;
}