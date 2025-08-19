/*
Lab Activity Number	: 2.2
Lab Activity Title	: C-Language: Basic I/O

Date Performed		: May 16, 2024
Date Submitted		: May 17, 2024

Machine Problem:
Create a program that converts the input Peso into its equivalent US dollar, Bahrain Dinar, Hongkong Dollar, and Japanese Yen exchange rates. 
(please refer to www.xe.com (Links to an external site.) for the current exchange rates)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso, dollar, dinar, hkdollar, yen;

     printf("\nEnter Amount in Peso: ");
     scanf("%f", &peso);    

     dollar = peso * 0.017;
     dinar = peso * 0.0066;
     hkdollar = peso * 0.14;
     yen = peso * 2.69;

     printf("\nUS Dollar = %.2f", dollar);
     printf("\nBahrain Dinar = %.2f", dinar);
     printf("\nHongkong Dollar = %.2f", hkdollar);
     printf("\nJapanese Yen = %.2f", yen);

     system("PAUSE");
     return 0;
}