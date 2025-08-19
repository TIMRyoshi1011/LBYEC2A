// Make a program to find the GCD of two numbers entered by the user. Put the GCD function in a separate function.

#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b, int num, int gcf);

int main()
{
    int num1, num2, n, gcf;

    printf("Enter two numbers:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("The GCD of %d and %d is %d", num1, num2, gcd(num1, num2, n, gcf));
    printf("\n");

    system("PAUSE");
    return 0;
}

int gcd(int a, int b, int num, int gcf)
{

    while (b != 0) {
        num = b;
        b = a % b;
        a = num;
    }
        gcf = a;

    return gcf;
}