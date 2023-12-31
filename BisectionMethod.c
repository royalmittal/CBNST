// Write a program to find the root of the equation f(x) = x^3 - 4x - 9 using Bisection Method.

#include<stdio.h>
#include<math.h>
#include<conio.h>

float f(float x)
{
    return (x*x*x - 4*x - 9);
}

void bisection(float *x, float a, float b, int *itr)
{
    *x=(a+b)/2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}

int main()
{
    int itr = 0, maxmitr;
    float x, a, b, allerr, x1;
    printf("\nEnter the values of a, b, allowed error and maximum iterations:\n");
    scanf("%f %f %f %d", &a, &b, &allerr, &maxmitr);
    bisection(&x, a, b, &itr);
    do
    {
        if (f(a)*f(x) < 0)
            b=x;
        else
            a=x;
        bisection(&x1, a, b, &itr);
        if (fabs(x1-x) < allerr)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x1);
            return 0;
        }
        x=x1;
    }
    while (itr < maxmitr);
    printf("The solution does not converge or iterations are not sufficient");
    return 1;
}

