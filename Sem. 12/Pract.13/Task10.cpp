#include <iostream>
using namespace std;

void enterArray(int* arr, int n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

bool binarySearch(const int* arr, int size, int target) {
    if (!arr) {
        return false;
    }

    if (size == 0) {
        return false;
    }

    int mid = size / 2;

    if (arr[mid] == target) {
        return true;
    }

    if (arr[mid] < target) {
        return binarySearch(arr + mid + 1, size - mid - 1, target);
    } else {
        return binarySearch(arr, mid, target);
    }
}

int main() {
    int n, x;
    cin >> n >> x;

    int* arr = new int[n];

    enterArray(arr, n);

    cout << binarySearch(arr, n, x) << endl;

    delete[] arr;
    return 0;
}