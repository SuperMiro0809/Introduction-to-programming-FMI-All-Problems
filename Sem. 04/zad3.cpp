#include <iostream>
using namespace std;

int reverseNum(int n) {
    int reversed = 0;

    while (n != 0) {
        reversed = (reversed * 10) + n % 10;

        n /= 10;
    }

    return reversed;
}

bool isNumPalindrom(int n, int k) {
    return n == k;
}

int main() {
    int num;
    cin >> num;
    
    bool isPalindrom = isNumPalindrom(num, reverseNum(num));

    cout << boolalpha << isPalindrom << endl;

    return 0;
}