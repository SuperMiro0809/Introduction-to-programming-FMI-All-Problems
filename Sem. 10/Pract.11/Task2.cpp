#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

int getLength(const char* str) {
    int length = 0;

    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }
    return length;
}

void reverseString(const char* str, char* result) {
    if (!str || !result) return;

    const char* ptr = str + getLength(str) - 1;

    while (ptr > str - 1) {
        *result = *ptr;
        result++;
        ptr--;
    }

    *result = TERMINATE_SYMBOL;
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    reverseString(str, result);

    cout << result << endl;
}