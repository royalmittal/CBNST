#include <stdio.h>
#include <math.h>
#include <conio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

float newtonBackward(float x, int n, float x0[], float y0[][10]) {
    float h = x0[1] - x0[0];
    float p = (x - x0[n]) / h;

    float y = y0[n][0];
    float term = 1;

    for (int i = 1; i <= n; i++) {
        term *= (p + i - 1) / i;
        y += term * y0[n][i];
    }

    return y;
}

int main() {
    int n;
    float x, x0[10], y0[10][10];

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x0[i]);
    }

    printf("Enter the values of y: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y0[i][0]);
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            y0[i][j] = y0[i][j - 1] - y0[i - 1][j - 1];
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &x);

    float result = newtonBackward(x, n - 1, x0, y0);
    printf("Interpolated value at x = %.2f is %.4f\n", x, result);

    return 0;
}