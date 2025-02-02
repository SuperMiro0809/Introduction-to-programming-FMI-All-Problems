#include <iostream>
using namespace std;

int getSumAbovePrimaryDialogan(int matrix[][4], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    int matrix[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << getSumAbovePrimaryDialogan(matrix, 4) << endl;
    return 0;
}