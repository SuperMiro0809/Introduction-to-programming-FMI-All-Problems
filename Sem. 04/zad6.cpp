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

bool isPreffixOfNumber(int n, int p) {
    while (n != 0) {
        int digitsCount = countDigits(n);

        int currentP = n % pow(10, digitsCount);

        if (currentP == p) return true;

        n /= 10;
    }

    return false;
}

bool isInfixOfNumber(int n, int infix) {
    int digitsCount = countDigits(n);
    int count = digitsCount - 1;

    while (count >= 0) {
        bool isInfixFound = isPreffixOfNumber(n, infix);

        if (isInfixFound) return true;

        n -= ((n / pow(10, count)) * pow(10, count)) ;
        count--;
    }

    return false;
}

int main() {
    int n, infix;
    cin >> n >> infix;

    cout << boolalpha << isInfixOfNumber(n, infix) << endl;

    return 0;
}