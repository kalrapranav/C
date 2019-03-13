/*
**       Author:  Pranav Kalra
**        REDID:  821916362
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  Correcting exception in lab 10
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


void main()
{
    srand( time( 0 ) );
     double b[ROWS +1][COLS + 1];
     for (int i = 0; i < ROWS; i++)
     {
         for(int j = 0; i < COLS; j++)
         {
             b[i][j] = 1 + (rand()%10);
         }
     }
     triangulate(b,ROWS,COLS);

}

void triangulate(double a[][COLS + 1], const size_t M, const size_t N)
{
    for(int i=1; i<= N; i++)
    {
        for(int j= i+1; j <= N; j++)
        {
            for(int k=N; k>= i; k--)
            { 
                a[j][k] -= a[i][k] * (a[j][i]/a[i][i]);
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


