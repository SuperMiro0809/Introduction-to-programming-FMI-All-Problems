#include <iostream>
using namespace std;

int* getDigitsArr(long N, int& digits);

int find(long N, int n);

int main() {
    long num;
    int n;
    cin >> num >> n;

    cout << find(num, n) << endl;
    return 0;
}

int* getDigitsArr(long N, int& digits) {
    long numCopy = N;

    while (numCopy != 0) {
        digits++;
        numCopy /= 10;
    }

    int* digitsArr = new int[digits];
    int index = 0;

    while (N != 0) {
        digitsArr[index++] = N % 10;
        N /= 10;
    }

    for (int i = 0; i < digits / 2; i++) {
        int temp = digitsArr[i];
        digitsArr[i] = digitsArr[digits - i - 1];
        digitsArr[digits - i - 1] = temp;
    }

    return digitsArr;
}

int find(long N, int n) {
    int digits = 0;
    int* digitsArr = getDigitsArr(N, digits);

    if (n >= digits) {
        return N;
    }

    int maxNum = INT_MIN;

    int to = digits - n;
    for (int i = 0; i <= to; i++) {
        int currentNum = 0;

        for (int j = i; j < i + n; j++) {
            currentNum = (currentNum * 10) + digitsArr[j];
        }

        if (currentNum > maxNum) {
            maxNum = currentNum;
        }
    }

    delete[] digitsArr;
    return maxNum;
}
