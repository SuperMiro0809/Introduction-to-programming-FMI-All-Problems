#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

unsigned charToDigit(char a) {
    if (a < '0' || a > '9') return 0;

    return a - '0';
}

unsigned int myAtoi(const char* str) {
    if (!str) return 0;

    unsigned result = 0;

    while (*str != TERMINATE_SYMBOL) {
        if (*str < '0' || *str > '9') {
            cout << "Not a number" << endl;
            return 0;
        }

        result = result * 10 + charToDigit(*str);
        str++;
    }

    return result;
}

int main() {
    char str[MAX_SIZE];

    cin.getline(str, MAX_SIZE);

    cout << myAtoi(str) << endl;
}