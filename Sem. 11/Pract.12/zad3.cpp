#include <iostream>
using namespace std;

void enterArray(int* arr, int n);

bool checkBit(int n, int k);

int findLength(const int* arr, int n, int k);

int* getResult(const int* arr, int n, int k, int length);

void printArray(const int* arr, int n);

int main() {
    int n, k;
    cin >> n;

    int* arr = new int[n];
    enterArray(arr, n);

    cin >> k;

    int length = findLength(arr, n, k);

    int* result = getResult(arr, n, k, length);

    printArray(result, length);

    delete[] arr;
    delete[] result;
    return 0;
}

void enterArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

bool checkBit(int n, int k) {
    int mask = 1;
    mask <<= k;

    return (mask & n) == mask;
}

int findLength(const int* arr, int n, int k) {
    if (!arr) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (checkBit(k, n - i - 1)) {
            count++;
        }
    }

    return count;
}

int* getResult(const int* arr, int n, int k, int length) {
    if (!arr) {
        return 0;
    }

    int* result = new int[length];
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (checkBit(k, n - i - 1)) {
            result[current++] = arr[i];
        }
    }

    return result;
}

void printArray(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}