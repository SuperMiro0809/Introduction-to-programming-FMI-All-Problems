#include <iostream>
using namespace std;

bool endsWith(long n, long k) {
    if (k == 0) {
        return true;
    }

    if (n == 0) {
        return false;
    }

    if (n % 10 != k % 10) {
        return false;
    }

    return endsWith(n / 10, k / 10);
}

int main() {
    long n, k;
    cin >> n >> k;

    cout << endsWith(n, k) << endl;

    return 0;
}