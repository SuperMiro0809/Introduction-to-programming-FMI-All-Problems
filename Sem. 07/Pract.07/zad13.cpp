#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void enterMatrix(char matrix[][MAX_COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool areColinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    return (area == 0); // if true => colinear
}

int main() {
    char matrix[MAX_ROWS][MAX_COLS];
    int n;
    cin >> n;

    enterMatrix(matrix, n);

    int points[MAX_ROWS * MAX_ROWS][2];
    int length = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '^') {
                points[length][0] = i;
                points[length][1] = j;
                length++;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < length - 2; i++) {
        for (int j = i + 1; j < length - 1; j++) {
            for (int k = j + 1; k < length; k++) {
                if (!areColinear(
                    points[i][0], points[i][1],
                    points[j][0], points[j][1],
                    points[k][0], points[k][1]
                )) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}
