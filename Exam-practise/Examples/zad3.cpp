#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int reversedNumber = 0;

    while (n != 0) {
        reversedNumber = (reversedNumber * 10) + n % 10;
        n /= 10;
    }

    return reversedNumber;
}

int getDigit(int num, int k) {
    int reversedNumber = reverseNumber(num);

    int pos = 1;

    while (reversedNumber != 0) {
        if (pos == k) {
            return reversedNumber % 10;
        }

        pos++;
        reversedNumber /= 10;
    }

    return -1;
}

int main() {
    int num, k;
    cin >> num >> k;

    cout << getDigit(num, k) << endl;

    return 0;
}