#include <iostream>
using namespace std;

unsigned int setBit(unsigned int n, unsigned int k) {
    int mask = 1;
    mask <<= k;

    return n | mask;
}

int main() {
    int n = 0b10010;
    int k = 3;

    cout << n << endl;
    cout << setBit(n, k) << endl;
}