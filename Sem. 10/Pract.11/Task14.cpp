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

char capitalToSmall(char s) {
    if (s < 'A' || s > 'Z') return s;

    return s - 'A' + 'a';
}

void replaceOccurrances(char* from, const char* to) {
    if (!from || !to) return;

    while (from <= to) {
        *from = '*';
        from++;
    }
}

void replaceSubstring(char* str, const char* substring) {
    if (!str || !substring) return;

    int substringLength = getLength(substring);
    const char* start = substring;
    const char* end = substring + substringLength - 1;

    while (*str != TERMINATE_SYMBOL) {
        if (capitalToSmall(*str) == capitalToSmall(*start)) {
            if (start == end) {
                replaceOccurrances(str - substringLength + 1, str);
            } else {
                start++;
            }
        } else {
            start = substring;
        }

        str++;
    }
}

int main() {
    char str[MAX_SIZE];
    char substring[MAX_SIZE];
    cin.getline(str, MAX_SIZE);
    cin.getline(substring, MAX_SIZE);

    replaceSubstring(str, substring);
    cout << str << endl;

    return 0;
}