// objective : To find the root of a given equation using Secant Method

// step 1 :find two values a & b 
// step 2 :find the value of c using the formula c = (a*f(b) - b*f(a))/(f(b) - f(a))
// a = b
// b = c
// step 3 :if f(c) = 0 then c is the root of the equation
// step 4 :if f(a)*f(c) < 0 then b = c else a = c
// step 5 :repeat the steps until the value of f(c) is greater than the tolerable error


#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (0)

float fl(float x)
{
    return (x*x) - (5*x) + 1;
}

float secant(float x0, float x1, float tol, int maxIter) {
    float x2, f0, f1, f2;
    int iter = 0;

    do {
        f0 = f(x0);
        f1 = f(x1);
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);
        printf("Iteration %d: x = %.8f, f(x) = %.8f\n", iter, x2, f2);
        if (fabsf(f2) < tol) {
            printf("Root found: x = %.6f\n", x2);
            return x2;
        }
        x0 = x1;
        x1 = x2;
        iter++;
    } while (iter < maxIter);
    printf("Maximum number of iterations reached. No root found.\n");
    return NAN; 
}

int main() {
    float x0, x1, tol;
    int maxIter;
    printf("Enter x0, x1, tolerance and maximum iterations: ");
    scanf("%f %f %f %d", &x0, &x1, &tol, &maxIter);
    secant(x0, x1, tol, maxIter);
    getch();
    return 0;
}