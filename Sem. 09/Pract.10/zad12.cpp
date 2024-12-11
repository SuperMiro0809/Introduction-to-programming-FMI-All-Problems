#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;
const int LETTER_DIFF = 32; // 'a' - 'A' = 97 - 65

void convertString(char* str) {
    if (!str) return;

    while (*str != TERMINATE_SYMBOL) {
        if (*str >= 'a' && *str <= 'z') {
            *str -= LETTER_DIFF; // 'a' - 'A' = 97 - 65
        }else if (*str >= 'A' && *str <= 'Z') {
            *str += LETTER_DIFF;
        }

        str++;
    }
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    convertString(str);

    cout << str << endl;
}