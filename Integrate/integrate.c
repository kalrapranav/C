#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct rectangle
{
    double width;
    double height;
};
typedef struct rectangle Rectangle;

struct trapezoid
{
    double aBase;
    double bBase;
    double height;
};
typedef struct trapezoid Trapezoid;

double rectArea(Rectangle rect)
{
    return rect.height*rect.width;
}
double trapeArea(Trapezoid trape)
{
    return trape.height*(trape.aBase+trape.bBase)/2.0;
}

double rectangle_method (double a, double b,int N)
{
    double step =  (b-a)/N;
    double x = a;
    double area = 0.0;
    Rectangle rect;
    rect.height = x;
    rect.width = step;
    while(x < b)
    {
        x+=step;
        rect.height = 2.0/(rect.height+x);
        area+=rectArea(rect);
        rect.height = x;
    }
}
double trapezoid_method(double a, double b,int N)
{
    double step = (b-a)/N;
    double x=a;
    double area = 0.0;
    double fx;
    Trapezoid trape;
    trape.aBase = x;
    trape.height=step;
    while(x<b)
    {
        x+=step;
        fx=1.0/x;
        trape.bBase=fx;
        area+=trapeArea(trape);
        trape.aBase=fx;
    }
    return area;
}

int main()
{
    int N=10;
    double a=1;
    double b=2;
    double a1,a2;
    //printf("%lf",a1);
    double integral=log(2)-log(1);
    printf("N         Rectangle         Error         Trapezoid         Error\n");
    for(N=10;N<=10000;N*=10)
    {
        a1=rectangle_method(a,b,N);
        //printf("%lf",a1);
        a2=trapezoid_method(a,b,N);
        printf("%-7d  %.13lf  %.13lf  %.13lf  %.13lf\n",N,a1,fabs(a1-integral),a2,fabs(a2-integral),integral);
    }
    return 0;
}







