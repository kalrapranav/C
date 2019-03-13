/*
**   Assignment:  Laboratory Assignment 03 "Maclaurin Series"
**
**     Filename:  MaclaurinSeries.c
**
**       Author:  Pranav Kalra
**        REDID:  821916362
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  The takes a radian value form user and calculate the approximate value for cos(x)
**                using Maclurin Series for 10 iterations. It also calculates the error difference
**                for the actual value of x for each iteration
**
**        Input:  Radian value for x.
**
**       Output:  The string "k: 0, cos(x): 1.000000, err: 1.999999e+00" for 10 iterations.
**
**    Algorithm:  Calculation of malcurian Series
**
**      Caveats:  Describe any known program bugs or limitations.
**      Version:  1.0
**
*/
#include <stdio.h>
#include <math.h>

long factorial(int n);
float Cos(float k, float x); //changed the return type to void from float and parametre  type to void
float Error(float f, float x); //changed the parametre type to void

void main()
{
    //k: 0, cos(x): 1.000000, err: 1.999999e+00
    printf("Enter a radian value for x to calculate cos(x): ");
    float x;
    scanf("%f", &x);
    printf("x = %f\n", x);
    for(float k = 0; k <= 10; k++)
    {
        printf("k: %f, cos(x): %f, err: %e\n",k, Cos(k, x), Error(k, x));
    }
}

long factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}

float Cos(float k, float x)   // function definition
{
    //Calculating value for cos(3.14)
    //float x = 3.14159;
    float r;
        int power = pow(x,2*k);
        int fact = factorial(2*k);
        int sign = pow(-1,k);
        float numerator;
        numerator = (sign * power);
        r = numerator / fact;
        //k: 0, cos(x): 1.000000, err: 1.999999e+00
        //printf("k: %f, cos(x): ",k);
        //printf("%f, Error: %f", r, Error());
    return r;

}

float Error(float f, float x)
{
    //float x = 3.14159;
    float e, abse;
    e = Cos(f,x) - cos(x);
    abse = fabs(e);
    return abse;
}

