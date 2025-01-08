#include <iostream>
using namespace std;

void enterArray(int* arr, int n);

void insertAt(int*& arr, size_t& len, int index, int elem);

void removeAt(int*& arr, size_t& len, int index);

void printArray(const int* arr, int n);

int main() {
    size_t n;
    cin >> n;

    int* arr = new int[n];

    enterArray(arr, n);

    insertAt(arr, n, 4, 125);

    printArray(arr, n);

    removeAt(arr, n, 1);

    printArray(arr, n);

    delete[] arr;
    return 0;
}

void enterArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void insertAt(int*& arr, size_t& len, int index, int elem) {
    if (index > len) {
        cout << "error" << endl;
        return;
    }

    int newL = len + 1;
    int* result = new int [newL];

    int curr = 0;
    for (int i = 0; i < newL; i++) {
        if (i == index) {
            result[curr++] = elem;
            result[curr++] = arr[i];
        } else {
            result[curr++] = arr[i];
        }
    }

    delete[] arr;
    arr = result;
    len = newL;
}

void removeAt(int*& arr, size_t& len, int index) {
    if (index < len) {
        cout << "error" << endl;
        return;
    }

    int newL = len - 1;
    int* result = new int [newL];

    int curr = 0;
    for (int i = 0; i < len; i++) {
        if (i == index) {
            continue;
        } else {
            result[curr++] = arr[i];
        }
    }

    delete[] arr;
    arr = result;
    len = newL;
}

void printArray(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
