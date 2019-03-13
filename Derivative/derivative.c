/*
**   Assignment:  Laboratory Assignment 06 "Derivative"
**
**     Filename:  derivative.c
**
**       Author:  Pranav Kalra
**        REDID:  821916362
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  The program is guessing number program which asks user to enter a number and tells
**                them it is too low or too high in order for them to have give multiple inputs to find
**                the correct number
**
**        Input:  Integer values for x from the user .
**
**       Output:  The derivative, cd, bd, fd, cdeff, bdeff and fdeff of the function.
**
**    Algorithm:  Binary search with user inputs to sort
**
**      Caveats:  Describe any known program bugs or limitations.
**      Version:  1.0
**
*/
#include <stdio.h>
#include <math.h>

double u (double x);
double dudx (double x);
double fdiff(double x, double h);
double bdiff(double x, double h);
double cdiff(double x, double h);
double fderr(double x, double h);
double bderr(double x, double h);
double cderr(double x, double h);

void main()
{
    int x;
    double h;
    printf("Enter a x: ");
    scanf("%1d", &x);
    printf("%d\n",x);
        for (double n = 1; n <= 8; n ++)
        {
            h = pow(10, (-1 * n) );
           printf("h: %e, x: %d, u(x): %e, du/dx: %e, fd: %e, bd: %e, cd: %e,\nfderr: %e, bderr: %e, cderr: %e\n"
           ,h, x, u(x), dudx(x), fdiff(x,h), bdiff(x,h), cdiff(x,h), fderr(x,h), bderr(x,h), cderr(x,h));

        }


}

double u (double x)
{
    return (pow(x,3.0));
}

double dudx (double x)
{
    return (3.0 * pow(x, 2.0));
}

double fdiff(double x, double h)
{
    double fd = (u(x + h) - u(x)) / h;
    return fd;
}
double bdiff(double x, double h)
{
    double bd = (u(x) - u(x-h))/h;
    return bd;
}
double cdiff(double x, double h)
{
    double cd = (u(x+h) - u(x-h)) / (2 * h);
    return cd;
}
double fderr(double x, double h)
{
    double err = fdiff(x,h) - dudx(x);
    double r = fabs(err);
    return r;
}
double bderr(double x, double h)
{
    double err = bdiff(x,h) - dudx(x);
    double r = fabs(err);
    return r;
}
double cderr(double x, double h)
{
    double err = cdiff(x,h) - dudx(x);
    double r = fabs(err);
    return r;
}
