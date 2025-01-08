#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enterArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int findUniqueNumber(const int* arr, int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }

    return result;
}

int main() {
    int arr[MAX_SIZE];
    int n;
    cin >> n;

    enterArray(arr, n);

    cout << findUniqueNumber(arr, n) << endl;
}