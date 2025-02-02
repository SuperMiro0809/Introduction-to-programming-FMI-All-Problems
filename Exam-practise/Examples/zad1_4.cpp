#include <iostream>
using namespace std;

int** transponseMatrix(int matrix[][4], int n, int m) {
    int** transMatrix = new int* [n];

    for (int i = 0; i < n; i++) {
        transMatrix[i] = new int[m];

        for (int j = 0; j < m; j++) {
            transMatrix[i][j] = matrix[j][i];
        }
    }

    return transMatrix;
}

int main() {
    int matrix[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
        }
    }

    int** transMatrix = transponseMatrix(matrix, 4, 4);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << transMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete[] transMatrix[i];
    }
    delete[] transMatrix;

    return 0;
}