#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

int getLength(const char* str) {
    if (!str) return 0;

    int length = 0;

    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

int compareNumbers(const char* num1, const char* num2) {
    if (!num1 || !num2) return 0;

    int num1Length = getLength(num1);
    int num2Length = getLength(num2);

    if (num1Length < num2Length) return -1;
    if (num1Length > num2Length) return 1;

    while (*num1 != TERMINATE_SYMBOL && *num1 == *num2) {
        num1++;
        num2++;
    }

    return *num1 - *num2;
}

int main() {
    char num1[MAX_SIZE];
    char num2[MAX_SIZE];

    cin.getline(num1, MAX_SIZE);
    cin.getline(num2, MAX_SIZE);

    int result = compareNumbers(num1, num2);

    switch (result) {
        case -1:
            cout << num1 << " < " << num2 << endl;
            break;
        case 0:
            cout << num1 << " = " << num2 << endl;
            break;
        case 1:
            cout << num1 << " > " << num2 << endl;
            break;
    }
}