
/* Function: simpson_one_third
 * ---------------------------
 * Calculates the integral of a function using Simpson's 1/3 rule.
 *
 * Parameters:
 * a - the lower limit of integration.
 * b - the upper limit of integration.
 * n - the number of subintervals (must be even).
 *
 * Returns:
 * The approximate value of the integral.
 */


#include<stdio.h>

float f(float x) {
    // Define the function to be integrated here
    return x * x; // Example: f(x) = x^2
}

float simpson_one_third(float a, float b, int n) {
    if (n % 2 != 0) {
        printf("n must be even.\n");
        return 0;
    }
    
    float h = (b - a) / n;
    float sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        sum += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return (h / 3) * sum;
}

int main() {
    float a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);

    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);

    printf("Enter the number of subintervals (n - must be even): ");
    scanf("%d", &n);

    float result = simpson_one_third(a, b, n);

    if (result != 0) {
        printf("The result of integration by 1/3 Simpson's method is: %.4f\n", result);
    }

    return 0;
}

