#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

char digitToChar(int s);

bool checkIfContains(const char * str, char s);

int analyzeArray(const char * str);

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << analyzeArray(str) << endl;
    return 0;
}

char digitToChar(int s) {
    if (s < 0 || s > 9) {
        return '0';
    }

    return s + '0';
}

bool checkIfContains(const char * str, char s) {
    if (!str) {
        return false;
    }

    while (*str != TERMINATE_SYMBOL) {
        if (*str == s) {
            return true;
        }
        str++;
    }

    return false;
}

int analyzeArray(const char * str) {
    if (!str) {
        return -1;
    }

    for (int i = 9; i >= 0; i--) {
        if (!checkIfContains(str, digitToChar(i))) {
            return i;
        }
    }

    return -1;
}