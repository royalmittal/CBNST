#include<stdio.h>
#define N 3

void gaussForward(float A[N][N+1], float x[N]) {
    int i, j, k;
    float ratio;

    for (i = 0; i < N-1; i++) {
        for (j = i + 1; j < N; j++) {
            ratio = A[j][i] / A[i][i];
            for (k = i; k < N+1; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    x[N-1] = A[N-1][N] / A[N-1][N-1];
    for (i = N-2; i >= 0; i--) {
        x[i] = A[i][N];
        for (j = i+1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main() {
    float A[N][N+1] = {
        {2, -1, 3, 5},
        {4, 2, -1, 3},
        {1, 3, 2, 9}
    };
    float x[N];

    gaussForward(A, x);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    return 0;
}