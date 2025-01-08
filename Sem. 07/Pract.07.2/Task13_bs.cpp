#include <iostream>
using namespace std;

const int MAX_SIZE = 1024;

void enterArray(int arr[], int n);

int findPosition(const int arr[], int n, int num);

void printArray(const int arr[], int n);

int main() {
    int n;
    cin >> n;

    if (n < 2 || n > 1024) {
        cout << "Incorrect data" << endl;
    }

    int arr[MAX_SIZE];
    enterArray(arr, n);

    int result[MAX_SIZE];
    int length = 0;

    for (int i = 0; i < n; i++) {
        if (length == 0 || arr[i] > result[length - 1]) {
            result[length++] = arr[i];
        } else {
            int pos = findPosition(result, length, arr[i]);
            result[pos] = arr[i];
        }
    }

    printArray(result, length);
}

void enterArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int findPosition(const int arr[], int n, int num) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}
