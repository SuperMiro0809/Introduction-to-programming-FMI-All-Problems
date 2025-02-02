#include <iostream>
using namespace std;

const int HEIGHT = 25;
const int WIDTH = 80;

void printRectangle(int height, int width, char s) {
    int topRows = (HEIGHT - height) / 2;

    for (int i = 0; i < topRows; i++) {
        cout << endl;
    }

    int leftCols = (WIDTH - width) / 2;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < WIDTH; i++) {
            if (i > leftCols && i <= leftCols + width) {
                cout << s;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    int bottomRows = HEIGHT - topRows - height;
    for (int i = 0; i < bottomRows; i++) {
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    printRectangle(n, m, '*');
    return 0;
}