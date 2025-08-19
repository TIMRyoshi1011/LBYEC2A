/*
Lab Activity Number	: 4.2
Lab Activity Title	: Functions Part 1 (Assignment)

Date Performed		: May 27, 2024
Date Submitted		: May 29, 2024

Machine Problem:
Write the following functions that compute the volume and surface of a sphere with radius r; a cylinder with circular base with radius r and height h; 
and a cone with circular base with radius r and height h. Place these functions in appropriate class. 
Define π (PI) as a constant variable equals to 3.14 then use it in the functions.
float sphereVolume(float r)
float sphereSurface(float r)
float cylinderVolume(float r, float h)
float cylinderSurface(float r, float h)
float coneVolume(float r, float h)
float coneSurface(float r, float h)

Now, prompt the user for the values of r and h, call the 6 functions, and print the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14
float vsphere(float r1);
float sasphere(float r2);
float vcylinder(float r3, float h3);
float sacylinder(float r4, float h4);
float vcone(float r5, float h5);
float sacone(float r6, float h6);

int main(int argc, char *argv[])
{
    float r, h;
    printf("Enter Value of Radius (r):\n");
    scanf("%f", &r);
    printf("Enter Value of Height (h):\n");
    scanf("%f", &h);

    printf("\nVolume of the Sphere = %.2f\n", vsphere(r));
    printf("Surface Area of the Sphere = %.2f\n", sasphere(r));
    printf("Volume of the Cylinder = %.2f\n", vcylinder(r,h));
    printf("Surface Area of the Cylinder = %.2f\n", sacylinder(r,h));
    printf("Volume of the Cone = %.2f\n", vcone(r,h));
    printf("Surface Area of the Cone = %.2f\n", sacone(r,h));

    system("PAUSE");
    return 0;
}

float vsphere(float r1)
{
    float v1;
    v1 = ((4 * pi) / 3) * r1 * r1 * r1;
    return v1;
}

float sasphere(float r2)
{
    float sa1;
    sa1 = 4 * pi * r2 * r2;
    return sa1;
}

float vcylinder(float r3, float h3)
{
    float v2;
    v2 = pi * r3 * r3 * h3;
    return v2;
}

float sacylinder(float r4, float h4)
{
    float sa2;
    sa2 = (2 * pi * r4 * h4) + (2 * pi * r4 * r4);
    return sa2;
}

float vcone(float r5, float h5)
{
    float v5;
    v5 = (pi / 3) * r5 * r5 * h5;
    return v5;
}

float sacone(float r6, float h6)
{
    float sa6;
    sa6 = pi * r6 * (r6 + sqrt((h6 * h6) + (r6 * r6)));
    return sa6;
}