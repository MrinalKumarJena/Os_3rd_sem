#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#define rows 3
#define cols 3

void add_matrices(int matrix1[rows][cols], int matrix2[rows][cols]) {
    int result[rows][cols];

    printf("Matrix Addition Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[rows][cols], int matrix2[rows][cols]) {
    int result[rows][cols];

    printf("Matrix Multiplication Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[rows][cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[rows][cols] = {{10,11,12}, {13,14,15}, {16,17,18}};

    int pid = fork();

    if (pid < 0) {
        printf("Fork failed");
    }
    else if (pid == 0) {
        printf("Child Process");
        add_matrices(matrix1, matrix2);
        printf("\n");


   }
    else {
        printf("Parent Process");
        multiply_matrices(matrix1, matrix2);
    }

    return 0;
}
