#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

void replaceOccurrances(const char* str, char* result, char x, char a, char b) {
    if (!str || !result) return;

    int index = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (*str == x) {
            if (index % 2 == 0) {
                *result = b;
            } else {
                *result = a;
            }
        } else {
            *result = *str;
        }

        index++;
        str++;
        result++;
    }

    *result = TERMINATE_SYMBOL;
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    char x, a, b;

    cin.getline(str, MAX_SIZE);
    cin >> x >> a >> b;

    replaceOccurrances(str, result, x, a, b);
    cout << result << endl;
}