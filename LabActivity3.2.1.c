/*
Lab Activity Number	: 3.2
Lab Activity Title	: C -Language: Conditional Statements

Date Performed		: May 24, 2024
Date Submitted		: May 24, 2024

Machine Problem:
The National Earthquake Information Centre has the following criteria to determine the earthquake’s damage. Here are the given Richter scale criteria 
and their corresponding characterization. The Richter scale serves as the input data and the characterization as output information. Use if-else conditional statements.
Richter scale characterization
n<5.0 Little or no damage
5.0 to <5.5 some damage
5.5 to <6.5 serious damage
6.5 to <7.5 disaster
Higher   catastrophe
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float scale;

    printf("Enter Richter Scale Value: \n");
    scanf("%f", &scale);

    if (scale<5.0)
    printf("Little or no damage\n");

    else if ((scale>=5.0) && (scale<5.5))
    printf("Some damage\n");

    else if ((scale>=5.5) && (scale<6.5))
    printf("Serious damage\n");

    else if ((scale>=6.5) && (scale<7.5))
    printf("Disaster\n");

    else if (scale>=7.5)
    printf("Catastrophe\n");

    else
    printf("Invalid value");

    system("PAUSE");
    return 0;
}
