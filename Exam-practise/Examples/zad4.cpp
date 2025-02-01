#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const char TERMINATE_SYMBOL = '\0';

bool isPrefix(const char* symbols, const char* word) {
    if (!symbols || !word) {
        return false;
    }

    while (*word != TERMINATE_SYMBOL) {
        if (*word != *symbols) {
            return false;
        }

        symbols++;
        word++;
    }

    return true;
}

bool doExist(const char* symbols, const char* word) {
    if (!symbols || !word) {
        return false;
    }

    while (*symbols != TERMINATE_SYMBOL) {
        if (isPrefix(symbols, word)) {
            return true;
        }

        symbols++;
    }

    return false;
}

int main() {
    char str[MAX_SIZE];
    char word[MAX_SIZE];

    cin.getline(str, MAX_SIZE);
    cin.getline(word, MAX_SIZE);

    cout << doExist(str, word) << endl;
    return 0;
}