#include <iostream>
using namespace std;

long fibbRec(long n, long* cache) {
    if (n == 1 || n == 2) {
        return n;
    }

    if (!cache[n]) {
        cache[n] = fibbRec(n - 1, cache) + fibbRec(n - 2, cache);
    }

    return cache[n];
}

long fibb(long n) {
    long* cache = new long[n + 1];
    long result = fibbRec(n, cache);

    delete[] cache;
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << fibb(n) << endl;

    return 0;
}