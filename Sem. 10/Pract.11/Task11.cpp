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

bool checkIfContains(const char* str, char s) {
    if (!str) return false;

    while (*str != TERMINATE_SYMBOL) {
        if (*str == s) {
            return true;
        }

        str++;
    }

    return false;
}

void fillDistinct(const char* fillStr, const char* checkStr, char* result) {
    if (!fillStr || !checkStr) return;

    while (*fillStr != TERMINATE_SYMBOL) {
        if (!checkIfContains(checkStr, *fillStr)) {
            *result = *fillStr;
            result++;
        }

        fillStr++;
    }
}

void findDistinct(const char* first, const char* second, char* result) {
    if (!first || !second) return;

    fillDistinct(first, second, result);
    result += getLength(result);

    fillDistinct(second, first, result);
    result += getLength(result);

    *result = TERMINATE_SYMBOL;
}

int main() {
    char first[MAX_SIZE];
    char second[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(first, MAX_SIZE);
    cin.getline(second, MAX_SIZE);

    findDistinct(first, second, result);
    cout << result << endl;

    return 0;
}