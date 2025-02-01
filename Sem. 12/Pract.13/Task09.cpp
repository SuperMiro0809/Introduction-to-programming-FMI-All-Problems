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

bool linearRec(const int* arr, int n, int x, int index) {
    if (!arr) {
        return false;
    }

    if (arr[index] == x) {
        return true;
    }

    if (index == n) {
        return false;
    }

    return linearRec(arr, n, x, index + 1);
}

bool itContains(const int* arr, int n, int x) {
    if (!arr) {
        return false;
    }

    bool result = linearRec(arr, n, x, 0);
    return result;
}

int main() {
    int n, x;
    cin >> n >> x;

    int* arr = new int[n];
    enterArray(arr, n);

    cout << itContains(arr, n, x) << endl;

    delete[] arr;
    return 0;
}