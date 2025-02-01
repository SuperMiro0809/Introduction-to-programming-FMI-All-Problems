#include <iostream>
using namespace std;

bool search(int n, int k) {
    if (n == 0) {
        return false;
    }

    if (k == n % 10) {
        return true;
    }

    return search(n / 10, k);
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << search(n, k) << endl;

    return 0;
}