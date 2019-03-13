/*
**       Author:  Pranav Kalra
**        REDID:  821916362
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  The program  is a functional linear system solver
**        Input:  No input from the user .
**
**       Output:  A 10*10 triangulated and updated array
**
**    Algorithm:  Matrix triangulation
**
**      Caveats:  Describe any known program bugs or limitations.
**      Version:  1.0
**
*/
#include <stdio.h>
#include <math.h>
#define ROWS 10
#define COLS 10

 void triangulate(double a[][COLS +1], const size_t M, const size_t N);
 void printArray(double a[][COLS+1]);
 void subsitute(double a[][COLS+2], double x[], const size_t N);

void main()
{
    srand( time( 0 ) );
    //double a[ROWS +1][COLS +1] = {{0,0,0,0},{0,1,3,-4},{0,1,1,-2},{0,-1,-2,-5}};
//     triangulate(a, ROWS, COLS);
     double b[ROWS +1][COLS + 1];
     for (int i = 0; i < ROWS; i++)
     {
         for(int j = 0; i < COLS; j++)
         {
             b[i][j] = 1 + (rand()%10);
         }
     }
     //double a[];
     triangulate(b,ROWS,COLS);
     subsitute(b,b,COLS);
}

void triangulate(double a[][COLS + 1], const size_t M, const size_t N)
{
    for(int i=1; i<= N; i++)
    {
        for(int j= i+1; j <= N; j++)
        {
            for(int k=N; k>= i; k--)
            {
                //int temp;
                //int secondVariable
                a[j][k] -= a[i][k] * (a[j][i]/a[i][i]);
                //temp = a[j][k];
                //a[j][k] = secondVariable;
                //secondVariable = temp;
            }
        }
    }
    printArray(a);
}

void printArray(double a[][COLS+1])
{
    int i, j;
    for (i = 1; i < (ROWS ); i++)
    {
      for (j = 1; j < (COLS); j++)
      {
        printf("%.2f ", a[i][j]);
      }
      printf("\n");
    }
}

void subsitute (double a[][COLS+2], double x[], const size_t N)
{
    int j, k;
    float t;
    for(j=N; j>=11; j--)
    {
        t=0;
        for(k= j+1; k<=N; k++)
        {
            t += a[j][k] * x[k];
            x[j] = (a[j][N] -t)/a[j][j];
            printf("Updating x[%d] to (%.2f - %.2f)/%.2f: %.2f\n,",
                    j, a[j][N+1], t, a[j][j], x[j]);
        }
    }
}
