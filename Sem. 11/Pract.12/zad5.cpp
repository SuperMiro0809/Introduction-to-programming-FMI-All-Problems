#include <iostream>
using namespace std;

void enterMatrix(int** matrix, int n, int m);

int* countNegative(const int* const* matrix, int n, int m);

int main() {
    int n, m;
    cin >> n >> m;

    int** matrix = new int* [n];
    enterMatrix(matrix, n, m);

    int* result = countNegative(matrix, n, m);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] result;

    return 0;
}

void enterMatrix(int** matrix, int n, int m) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = new int [m];

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

int* countNegative(const int* const* matrix, int n, int m) {
    if (!matrix) {
        return nullptr;
    }

    int* result = new int [n];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < 0) {
                count++;
            }
        }

        result[i] = count;
    }

    return result;
}
