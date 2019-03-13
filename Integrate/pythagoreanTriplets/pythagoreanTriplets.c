#include <stdio.h>
#define PI 3.1415926

void circumference(double a);
void area(double b);
void volume(double c);

int main(void)
{
    void (*f[3])(double) = {circumference, area, volume};
    printf("=== Circles & Spheres Menu ===\n\n");

    printf("Please select from the options below:\n\n");
    printf("(0) Calculate the circumference of a circle.\n(1) Calculate the area of a circle.\n(2) Calculate the volume of a sphere.\n\n");
    printf("Enter your selection:");
    int choice;
    scanf("%d", &choice);

    while(choice >= 0 && choice < 3)
    {
        (*f[choice])(choice);

        printf("%s", "Enter a number between 0 and 2, 3 to end");
        scanf("%d", &choice);
    }
    puts("Invalid selection!\n");
}
void circumference(double a)
{
    double radius;
    double circumference = 0;
    printf(" Enter the radius of your figure:\n");
    scanf("%lf",&radius);
    if (radius >= 0)
    {
    printf(" Calculating circumference of circle with radius %lf\n", radius);
    circumference = (2*PI)*radius;
    printf("The result is: %lf\n", circumference);
    }
    else
        printf("Radius must be greater than or equal to 0\n");
}
void area(double a)
{
    double radius;
    double area = 0;
    int square;
    printf(" Enter the radius of your figure:\n");
    scanf("%lf",&radius);
    if (radius >= 0)
    {
    printf(" Calculating area of circle with radius %lf\n", radius);
    square = radius * radius;
    area = square * PI;
    printf("The result is: %lf\n", area);
    }
   else
        printf("Radius must be greater than or equal to 0\n");
}
void volume(double a)
{
    double radius;
    double volume = 0;
    int cube;
    printf(" Enter the radius of your figure:\n");
    scanf("%lf",&radius);
    if (radius >= 0)
    {
         printf(" Calculating volume of circle with radius %lf\n", radius);
         cube = radius * radius * radius;
         volume = cube * PI;
         printf("The result is: %lf\n", volume);
    }
    else
        printf("Radius must be greater than or equal to 0\n");

}
