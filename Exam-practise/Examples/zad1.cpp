#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

char smallToCapital(char s) {
    if (s < 'a' || s > 'z') {
        return s;
    }

    return s - 'a' + 'A';
}

char capitalToSmall(char c) {
    if (c < 'A' || c > 'Z') {
        return c;
    }

    return c - 'A' + 'a';
}

void revert(char* str) {
    if (!str) {
        return;
    }

    while (*str != TERMINATE_SYMBOL) {
        if (*str >= 'A' && *str <= 'Z') {
            *str = capitalToSmall(*str);
        } else if (*str >= 'a' && *str <= 'z') {
            *str = smallToCapital(*str);
        }

        str++;
    }
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    revert(str);

    cout << str << endl;
    return 0;
}