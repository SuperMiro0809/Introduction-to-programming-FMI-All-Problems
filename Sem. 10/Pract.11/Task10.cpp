#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 50;

char smallToCapital(char s) {
    if (s < 'a' || s > 'z') return s;

    return s - 'a' + 'A';
}

void makeWordStartCapital(const char* str, char* result) {
    if (!str || !result) return;

    bool afterSpace = false;
    bool isStart = true;

    while (*str != TERMINATE_SYMBOL) {
        if (*str == ' ' || *str == '\t') {
            afterSpace = true;
            *result = *str;
        } else {
            if (afterSpace || isStart) {
                *result = smallToCapital(*str);
                afterSpace = false;
                isStart = false;
            } else {
                *result = *str;
            }
        }

        result++;
        str++;
    }

    *result = TERMINATE_SYMBOL;
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    makeWordStartCapital(str, result);
    cout << result << endl;
}