#include <iostream>
using namespace std;

int reverse(int n, int reversed = 0) {
    if (n == 0) {
        return reversed;
    }

    int digit = n % 10;
    return reverse(n / 10, reversed * 10 + digit);
}

int main() {
    int n;
    cin >> n;

    cout << reverse(n) << endl;
    return 0;
}