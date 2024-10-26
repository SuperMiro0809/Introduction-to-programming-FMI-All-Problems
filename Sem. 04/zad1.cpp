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

int main() {
    int n, k;
    cin >> n >> k;

    int powResult = pow(n, k);
    cout << powResult << endl;

    return 0;
}