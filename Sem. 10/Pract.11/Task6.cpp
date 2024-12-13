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

void getSubstring(const char* str, char* result, int beg, int end) {
    if (!str || !result) return;

    int strLength = getLength(str);

    if (beg > strLength) {
        *result = TERMINATE_SYMBOL;
        return;
    }

    if (end > strLength) {
        end = strLength - 1;
    }

    const char* left = str + beg;
    const char* right = str + end;

    while (left <= right) {
        *result = *left;
        left++;
        result++;
    }

    *result = TERMINATE_SYMBOL;
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    int beg, end;
    cin.getline(str, MAX_SIZE);
    cin >> beg >> end;

    getSubstring(str, result, beg, end);

    cout << result << endl;
}