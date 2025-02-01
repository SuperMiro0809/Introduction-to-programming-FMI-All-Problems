#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const char TERMINATE_SYMBOL = '\0';

char capitalToSmall(char c);

int getStringLength(const char* str);

bool chekcIfContains(const char* str, char s);

bool analyzeArray(const char* str);

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << analyzeArray(str) << endl;
    return 0;
}

char capitalToSmall(char c) {
    if (c < 'A' || c > 'Z') {
        return c;
    }

    return c - 'A' + 'a';
}

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

bool chekcIfContains(const char* str, char s) {
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

bool analyzeArray(const char* str) {
    if (!str) {
        return false;
    }

    int length = getStringLength(str);

    for (int i = 0; i < length; i++) {
        char el = str[i];

        if (el >= 'A' && el <= 'Z') {
            if (!chekcIfContains(str, capitalToSmall(el))) {
                return false;
            }
        }
    }

    return true;
}
