#include <stdio.h>
#include <math.h>

float C (float N);
void main()
{
    for(int i = 0; i <= 20; i++)
    {
        printf("%f\n",C(i));
    }


}

float C (float N)
{
    float k = N/2;
    float a = N + 1 + (1/N);
    if  (N == 0 || N == 1)
    {
        return 0;
    }
    else
    {
        return a + C(k - 1) + C(N - k);
    }
}
