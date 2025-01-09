#include <iostream>
using namespace std;

void enterArray(int* arr, int n);

void reverseArray(int* arr, int n);

void printArray(const int* arr, int n);

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    enterArray(arr, n);

    reverseArray(arr, n);
    printArray(arr, n);

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

void reverseArray(int* arr, int n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
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