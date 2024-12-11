#include <iostream>
using namespace std;

int at(const int* arr, unsigned int idx) {
    arr += idx;
    return *arr;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
    int index;
    cin >> index;

    cout << at(arr, index) << endl;
}