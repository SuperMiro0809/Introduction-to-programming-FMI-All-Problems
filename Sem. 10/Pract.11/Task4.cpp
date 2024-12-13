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

bool checkIfMatch(const char* pattern, const char* str) {
    if (!pattern || !str) return false;

    int patternLength = getLength(pattern);

    const char* end = str + patternLength - 1;

    while (str <= end) {
        if (*str != *pattern) return false;

        str++;
        pattern++;
    }

    return true;
}

int countPatternOccurances(const char* str, const char* pattern) {
    if (!str || !pattern) return 0;

    int count = 0;

    while(*str != TERMINATE_SYMBOL) {
        if (checkIfMatch(pattern, str)) {
            count++;
        }

        str++;
    }

    return count;
}

int main() {
    char str[MAX_SIZE];
    char pattern[MAX_SIZE];

    cin.getline(str, MAX_SIZE);
    cin.getline(pattern, MAX_SIZE);

    cout << countPatternOccurances(str, pattern) << endl;
}