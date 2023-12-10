#include <stdio.h>

double lagrangeInterpolation(double x[], double y[], int n, double xi) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    double x[] = {1, 2, 3, 4};
    double y[] = {2, 4, 1, 5};
    
    int n = sizeof(x) / sizeof(x[0]);
    
    double xi = 2.5;
    double interpolatedValue = lagrangeInterpolation(x, y, n, xi);
    
    printf("Interpolated value at xi = %.1lf is %.2lf\n", xi, interpolatedValue);
    
    return 0;
}