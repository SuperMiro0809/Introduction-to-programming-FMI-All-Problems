#include <iostream>
using namespace std;

void mySwap(int*& ptr1, int*& ptr2) {
    int* ptr3 = ptr1;
    ptr1 = ptr2;
    ptr2 = ptr3;
}

int main() {
    int a, b;
    cin >> a >> b;

    int* ptr1 = &a;
    int* ptr2 = &b;

    mySwap(ptr1, ptr2);

    cout << *ptr1 << " " << *ptr2 << endl;
}