#include <iostream>
using namespace std;

void enterArray(size_t* arr, size_t n);

size_t reverseNumber(size_t num);

bool lexiographySort(size_t first, size_t second);

void sortLex(size_t* nums, size_t N);

int main() {
    size_t n;
    cin >> n;

    size_t* arr = new size_t[n];

    enterArray(arr, n);

    sortLex(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}

void enterArray(size_t* arr, size_t n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

size_t reverseNumber(size_t num) {
    int n = 0;

    while (num != 0) {
        n = (n * 10) + num % 10;
        num /= 10;
    }

    return n;
}

bool lexiographyCheck(size_t first, size_t second) {
    size_t reverseF = reverseNumber(first);
    size_t reverseS = reverseNumber(second);

    while (reverseF != 0 && reverseS != 0) {

        if (reverseF % 10 > reverseS % 10) {
            return true;
        } else if (reverseF % 10 < reverseS % 10) {
            return false;
        }

        reverseF /= 10;
        reverseS /= 10;
    }

    if (!reverseF) {
        return false;
    } else {
        return true;
    }
}

void sortLex(size_t* nums, size_t N) {
    if (!nums) {
        return;
    }

    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < N; j++) {
            if (lexiographyCheck(nums[minIndex], nums[j])) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
}