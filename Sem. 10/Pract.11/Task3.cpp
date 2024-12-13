#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

char capitalToSmallLetter(char s) {
    if (s < 'A' || s > 'Z') return s;

    return s - 'A' + 'a';
}

void convertToLowerLetters(const char* str, char* result) {
    while (*str != TERMINATE_SYMBOL) {
        if (*str >= 'A' && *str <= 'Z') {
            *result = capitalToSmallLetter(*str);
        } else {
            *result = *str;
        }

        result++;
        str++;
    }
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    convertToLowerLetters(str, result);

    cout << result << endl;
    return 0;
}