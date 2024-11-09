#include <iostream>
using namespace std;

int squareRootToLower(int number) {
    int result = 1;

    if (number < 0) return -1;

    if (number == 0 || number == 1) return number;

    for (int i = 0; i * i <= number; i++) {
        result++;
    }

    return result;
}

int main() {
    int num;
    cin >> num;

    cout << squareRootToLower(num) << endl;

    return 0;
}