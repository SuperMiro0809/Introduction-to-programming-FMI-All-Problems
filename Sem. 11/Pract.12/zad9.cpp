#include <iostream>
using namespace std;

void enterMatrix(int** arr, int n, int m);

// 1 const = elementite na redovete sa constanti
// 2 const = pointarite na redovete sa constanti
bool checkEdges(const int* const* arr, int node1, int node2, int n);

int** getMatrix(const int* const* arr, int n, int edges);

void printMatrix(const int* const* matrix, int n, int m);

int main() {
    int n;
    cin >> n;

    int** arr = new int* [n];

    enterMatrix(arr, n, 2);

    int edges = n + 1;
    int** matrix = getMatrix(arr, n, edges);

    printMatrix(matrix, edges, edges);

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }

    delete[] arr;

    for (int i = 0; i < edges; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    return 0;
}

void enterMatrix(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        arr[i] = new int [m];

        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

bool checkEdges(const int* const* arr, int node1, int node2, int n) {
    for (int i = 0; i < n; i++) {
        if ((arr[i][0] == node1 && arr[i][1] == node2) || (arr[i][0] == node2 && arr[i][1] == node1)) {
            return true;
        }
    }

    return false;
}

int** getMatrix(const int* const* arr, int n, int edges) {
    int** matrix = new int* [edges];

    for (int i = 0; i < edges; i++) {
        matrix[i] = new int [edges];

        for (int j = 0; j < edges; j++) {
            matrix[i][j] = checkEdges(arr, i, j, n);
        }
    }

    return matrix;
}

void printMatrix(const int* const* matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
