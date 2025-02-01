#include <iostream>
using namespace std;

void printHelper(unsigned int N, unsigned int end) {
    for (int i = N; i >= end; i--) {
        cout << i << " ";
    }
    cout << endl;
}

void printNumbersRec(unsigned int N, unsigned int M) {
    if (M == 0) {
        return;
    }

    printHelper(N, M);

    printNumbersRec(N, M - 1);
}

void printNumbers(unsigned int N) {
    printNumbersRec(N, N);
}

int main() {
    int n;
    cin >> n;

    printNumbers(n);

    return 0;
}