#include <iostream>
using namespace std;

int isPerfectRec(int n, int del) {
    if (del == 1) {
        return 1;
    }

    if (n % del == 0) {
        return del + isPerfectRec(n, del - 1);
    }

    return 0 + isPerfectRec(n, del - 1);
}

bool isPerfect(int n) {
    int sum = isPerfectRec(n, n / 2);
    return n == sum;
}

int main() {
    int n;
    cin >> n;

    cout << isPerfect(n) << endl;

    return 0;
}