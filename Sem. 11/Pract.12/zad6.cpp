#include <iostream>
using namespace std;

void enterArray(int* arr, int n);

int countBeforeK(const int* arr, int n, int k);

int countAfterK(const int* arr, int n, int k);

int* getFirstHalf(const int* arr, int n, int k, int l);

int* getSecondHalf(const int* arr, int n, int k, int l);

int* reorderArray(const int* arr, int n, int k);

int main() {
    int n, k;
    cin >> n;
    int* arr = new int[n];
    enterArray(arr, n);

    cin >> k;

    int* result = reorderArray(arr, n, k);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    delete[] arr;
    delete[] result;
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

int countBeforeK(const int* arr, int n, int k) {
    if (!arr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < k) {
            count++;
        }
    }
    return count;
}

int countAfterK(const int* arr, int n, int k) {
    if (!arr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            count++;
        }
    }
    return count;
}

int* getFirstHalf(const int* arr, int n, int k, int l) {
    if (!arr) {
        return nullptr;
    }

    int* firstHalf = new int[l];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < k) {
            firstHalf[j++] = arr[i];
        }
    }

    return firstHalf;
}

int* getSecondHalf(const int* arr, int n, int k, int l) {
    if (!arr) {
        return nullptr;
    }

    int* secondHalf = new int[l];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            secondHalf[j++] = arr[i];
        }
    }

    return secondHalf;
}

int* reorderArray(const int* arr, int n, int k) {
    if (!arr) {
        return nullptr;
    }

    int beforeK = countBeforeK(arr, n, k);
    int afterK = countAfterK(arr, n, k);

    int* fistHalf = getFirstHalf(arr, n, k, beforeK);
    int* secondHalf = getSecondHalf(arr, n, k, afterK);

    int* result = new int[n];

    int length = 0;
    for (int i = 0; i < beforeK; i++) {
        result[length++] = fistHalf[i];
    }

    result[length++] = k;

    for (int i = 0; i < afterK; i++) {
        result[length++] = secondHalf[i];
    }

    return result;
}