/*
**   Assignment:  Laboratory Assignment 03 "Standard Logistic Function"
**
**     Filename:  standardLogisticFunction.c
**
**       Author:  Pranav Kalra
**        REDID:  821916362
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  The program is prompting to get a user input and using it to find the standard logistic
**                value if that function. Also it shows the standard logistic value for 1,10,10
**
**        Input:  Float values from the user .
**
**       Output:  Value of the standard logistic function
**
**    Algorithm:  Standard logistic function
**
**      Caveats:  Describe any known program bugs or limitations.
**      Version:  1.0
**
*/
#include <stdio.h>
#include <math.h>
//Math library

//function prototype
void logistic(float x);
//main function
void main()
{
    float userInput;
    printf("Enter a number !\n");
    scanf("%f",&userInput);
    printf("Your number was: %f\n",userInput);
    printf("\nFor x = %f, ", userInput);
    logistic(userInput);
    printf("\nFor x = 0, ");
    logistic(0);
    printf("\nFor x = 10, ");
    logistic(10);
    printf("\nFor x = -10, ");
    logistic(-10);


}
//Logistic function
void logistic(float x)
{
    //default parameters;
    //k = 1.0, x0 = 0.0, and L = 1.0
    float k = 1.0;
    float x0 = 0.0;
    float L = 1.0;
    float den = (k * -1)*(x - x0);
    float denominator;
    denominator = 1 + exp(den);
    float fx;
    fx = L/denominator;
    printf("the logistic function is: %f \n",fx);
}
