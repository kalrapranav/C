#include <stdio.h>
#include <math.h>

long factorial(int n);
float Cos(float k, float x);
float Bessel (float k, float x);
float Ratio (float k, float x);
float approxRatio (float x);
float Error(float k, float x);

void main()
{
    float x = 3.14;
    for(float k = 0; k <= 10; k++)
    {
        //k: 0, cos(x): 1.000000, err: 1.999999e+00
        printf("k: %f, cos(x): %f, J0(x): %f, Ratio: %f, approxRatio: %e, Error: %f\n",
               k , Cos(k,x), Bessel(k,x), Ratio(k,x), approxRatio(x), Error(k,x));
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
float Bessel (float k, float x)
{
    float r;
        float n = 2*k;
        int power = pow(x,n);
        int fact = factorial((n/2));
        int pow2 = pow(2,n);
        int sign = pow(-1,k);
        float numerator = sign * power;
        float denominator = pow2 * fact;
        r = numerator / denominator;
    return r;
}

float Ratio (float k, float x)
{
    float r;
    r = Cos(k,x)/Bessel(k,x);
    return r;
}

float approxRatio (float x)
{
    float pi = 3.14159;
    float f;
    f = pi*(x/2);
    float r = sqrt(r);
    return r;

}
float Error(float k, float x)
{
    float e, abse;
    e = Ratio(k,x) - approxRatio(x);
    abse = fabs(e);
    return abse;
}
