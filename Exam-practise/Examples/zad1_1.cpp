#include <iostream>
using namespace std;

int* getResult(const int* a, const int* b, int aL, int bL) {
    if (!a || !b) {
        return nullptr;
    }

    int* result = new int[aL + bL];
    int minL = aL > bL ? bL : aL;
    int index = 0;
    int aIndex = 0;
    int bIndex = 0;

    while (aIndex < aL && bIndex < bL) {
        if (a[aIndex] > b[bIndex]) {
            result[index++] = b[bIndex];
            bIndex++;
        } else {
            result[index++] = a[aIndex];
            aIndex++;
        }
    }

    while (aIndex < aL) {
        result[index++] = a[aIndex];
        aIndex++;
    }

    while (bIndex < bL) {
        result[index++] = b[bIndex];
        bIndex++;
    }

    return result;
}

int main() {
    int a[] = { 1, 3, 5, 9 };
    int b[] = { 2, 4, 5, 6, 8, 10, 11 };

    int* arr = getResult(a, b, 4, 7);

    for (int i = 0; i < 11; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}