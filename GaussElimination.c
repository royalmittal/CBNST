#include <stdio.h>
#include<conio.h>
#include<math.h>

#define N 3

void print_matrix(double matrix[N][N+1]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N+1; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussian_elimination(double matrix[N][N+1]) {
    int i, j, k;
    double factor;

    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            factor = matrix[j][i] / matrix[i][i];
            for (k = i; k < N+1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    for (i = N-1; i >= 0; i--) {
        for (j = i-1; j >= 0; j--) {
            factor = matrix[j][i] / matrix[i][i];
            for (k = i; k < N+1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    for (i = 0; i < N; i++) {
        factor = matrix[i][i];
        for (j = 0; j < N+1; j++) {
            matrix[i][j] /= factor;
        }
    }
}

int main() {
    double matrix[N][N+1] = {{1, 14, -16, 8}, {-13, -1, 31, -11}, {-11, 1, 16, -3}};
    printf("Original matrix:\n");
    print_matrix(matrix);
    gaussian_elimination(matrix);
    printf("Solved matrix:\n");
    print_matrix(matrix);
    return 0;
}

// #include <stdio.h>

// #define N 3

// int main() {
//     double matrix[N][N+1] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     int i, j, k;
//     double factor;

//     for (i = 0; i < N; i++) {
//         for (j = i+1; j < N; j++) {
//             factor = matrix[j][i] / matrix[i][i];
//             for (k = i; k < N+1; k++) {
//                 matrix[j][k] -= factor * matrix[i][k];
//             }
//         }
//     }

//     for (i = N-1; i >= 0; i--) {
//         for (j = i-1; j >= 0; j--) {
//             factor = matrix[j][i] / matrix[i][i];
//             for (k = i; k < N+1; k++) {
//                 matrix[j][k] -= factor * matrix[i][k];
//             }
//         }
//     }

//     for (i = 0; i < N; i++) {
//         printf("x%d = %f\n", i+1, matrix[i][N] / matrix[i][i]);
//     }

//     return 0;
// }
