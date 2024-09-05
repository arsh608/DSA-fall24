#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H
void matrixMultiply(int** mat1, int** mat2, int** result, int rows1, int cols1, int cols2);

#endif

#include <iostream>
#include "matrix_multiply.h"

void matrixMultiply(int** mat1, int** mat2, int** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1 = 2, cols1 = 3, cols2 = 2;

    int** mat1 = new int*[rows1];
    int** mat2 = new int*[cols1];
    int** result = new int*[rows1];

    for (int i = 0; i < rows1; i++) {
        mat1[i] = new int[cols1];
    }

    for (int i = 0; i < cols1; i++) {
        mat2[i] = new int[cols2];
    }

    for (int i = 0; i < rows1; i++) {
        result[i] = new int[cols2];
    }
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
    mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;

    mat2[0][0] = 7; mat2[0][1] = 8;
    mat2[1][0] = 9; mat2[1][1] = 10;
    mat2[2][0] = 11; mat2[2][1] = 12;
    matrixMultiply(mat1, mat2, result, rows1, cols1, cols2);

    cout << "Result Matrix:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows1; i++) {
        delete[] mat1[i];
        delete[] result[i];
    }
    for (int i = 0; i < cols1; i++) {
        delete[] mat2[i];
    }

    delete[] mat1;
    delete[] mat2;
    delete[] result;
    return 0;
}
