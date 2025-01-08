#include <iostream>
using namespace std;

bool isEven(int n) {
    return !(n & 1);
}

int main() {
    int n;
    cin >> n;

    cout << isEven(n) << endl;
}