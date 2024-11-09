#include <iostream>
using namespace std;

int pow(int a, int b) {
    int result = 1;

    for (int i = 0; i < b; i++) {
        result *= a;
    }

    return result;
}

int getLastDigitsOfNumber(int& num, int k) {
    int result = 0;

    for (int i = 0; i < k; i++) {
        int digit = num % 10;
        
        if (i == 0) {
            result += digit;
        } else {
            result = result + (pow(10, i) * digit);
        }

        num /= 10;
    }

    return result;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    cout << getLastDigitsOfNumber(a, k) << endl;
}