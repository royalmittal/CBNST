#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x) {
    // Define the function to integrate here
    // Example: f(x) = x^2
    return x * x;
}

// Trapezoidal method for numerical integration
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = (f(a) + f(b)) / 2.0; // First and last terms in trapezoidal formula

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h); // Sum the values of f at intermediate points
    }

    return sum * h; // Multiply by the step size to get the final result
}

int main() {
    double lower, upper;
    int subintervals;

    // Reading the lower and upper limits of integration
    printf("Enter the lower and upper limits of integration: ");
    scanf("%lf %lf", &lower, &upper);

    // Reading the number of subintervals
    printf("Enter the number of subintervals: ");
    scanf("%d", &subintervals);

    // Calculate the result
    double result = trapezoidal(lower, upper, subintervals);

    // Output the result
    printf("The integral of the function within the given limits is: %lf\n", result);

    return 0;
}


