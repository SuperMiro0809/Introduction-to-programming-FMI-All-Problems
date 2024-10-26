#include <iostream>
using namespace std;

int pow(int n, int k) {
    int res = 1;

    if (k == 0) return 0;

    for (int i = 0; i < k; i++) {
        res *= n;
    }

    return res;
}

int countDigits(int n) {
    int count = 0;

    while(n != 0) {
        count++;
        n /= 10;
    }

    return count;
}

bool isSuffixOfNumber(int n, int s) {
    int digitsCount = countDigits(n);

    for (int i = 1; i <= digitsCount; i++) {
        int currentS = n % pow(10, i);

        if (currentS == s) return true;
    }

    return false;
}

int main() {
    int n, suffix;
    cin >> n >> suffix;

    cout << boolalpha << isSuffixOfNumber(n, suffix) << endl;

    return 0;
}