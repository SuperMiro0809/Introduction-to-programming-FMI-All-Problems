#include <iostream>
using namespace std;

void enterArray(int* arr, int n);

bool isPrimeNumber(int n);

int countPrimeNumbers(const int* arr, int n);

int* getPrimeNumebrs(const int* arr, int n, int length);

void printArray(const int* arr, int n);

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    enterArray(arr, n);

    int length = countPrimeNumbers(arr, n);
    int* result = getPrimeNumebrs(arr, n, length);

    printArray(result, length);

    delete[] result;
    delete[] arr;

    return 0;
}

void enterArray(int* arr, int n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

bool isPrimeNumber(int n) {
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int countPrimeNumbers(const int* arr, int n) {
    if (!arr) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (isPrimeNumber(arr[i])) {
            count++;
        }
    }

    return count;
}

int* getPrimeNumebrs(const int* arr, int n, int length) {
    if (!arr) {
        return nullptr;
    }

    int* result = new int[length];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (isPrimeNumber(arr[i])) {
            result[j++] = arr[i];
        }
    }

    return result;
}

void printArray(const int* arr, int n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}