/*
Lab Activity Number	: 3.2
Lab Activity Title	: C -Language: Conditional Statements

Date Performed		: May 24, 2024
Date Submitted		: May 24, 2024

Machine Problem:
Conversions: This set of problems involves conversions of a value in one unit to another unit. Each conversion option should prompt the user for a value 
in the specified units and then print the converted value, along with the units.
Option1: convert inch to yard
Option 2: convert revolution per minute to Hertz
Option 3: converts degrees Fahrenheit (Tf) to degrees Celsius(Tc)
Use SWITCH statement so that it will simply select from those given conversions:
(1) Conversions from inch to yard
(2) Conversions from RPM to Hertz
(3) Conversions from deg. F to deg. C
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option;
    float value, converted;

    printf("Select Conversion Option: \n1. Inch to Yard\n2. Revolution per minute to Hertz\n3. Degrees Farenheit to Degrees Celcius\n");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
        printf("\nEnter Value in Inches (in):\n");
        scanf("%f", &value);

        converted = value * 0.0278;

        printf("\nThe equivalent value is %.2f", converted);

            if (value == 36)
            printf("yd\n");

            else
            printf("yds\n");
        break;

        case 2:
        printf("\nEnter Value in Revolution per minute (RPM):\n");
        scanf("%f", &value);

        converted = value * 0.0167;

        printf("\nThe equivalent value is %.2f", converted);
        printf("Hz\n");
        break;

        case 3:
        printf("\nEnter Value in Degrees Farenheit (deg.F):\n");
        scanf("%f", &value);

        converted = (value - 32) * 5 / 9;

        printf("\nThe equivalent value is %.1f", converted);
        printf("deg.C\n");
        break;

        default:
        printf("\nInvalid Option\n");
    }

    system("PAUSE");
    return 0;
}