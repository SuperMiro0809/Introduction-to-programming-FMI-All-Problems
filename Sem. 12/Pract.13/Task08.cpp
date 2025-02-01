#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const char TERMINATE_SYMBOL = '\0';

int getStringLength(const char* str) {
    if (!str) {
        return 0;
    }

    int length = 0;

    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

bool isPalindromeRec(const char* start, const char* end) {
    if (start == end) {
        return true;
    }

    if (*start != *end) {
        return false;
    }

    return isPalindromeRec(start + 1, end - 1);
}

bool isPalindrome(const char* str) {
    if (!str) {
        return false;
    }

    int length = getStringLength(str);
    const char* end = str + length - 1;
    int result = isPalindromeRec(str, end);

    return result;
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << isPalindrome(str) << endl;

    return 0;
}