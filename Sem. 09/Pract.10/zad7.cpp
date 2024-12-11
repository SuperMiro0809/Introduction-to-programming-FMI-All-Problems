#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

bool isPrefix(const char* pattern, const char* text) {
    if (!pattern || !text) return 0;

    while (*pattern != TERMINATE_SYMBOL) {
        if (*pattern != *text) {
            return false;
        }

        pattern++;
        text++;
    }

    return true;
}

int main() {
    char word[MAX_SIZE];
    char pattern[MAX_SIZE];

    cin.getline(word, MAX_SIZE);
    cin.getline(pattern, MAX_SIZE);

    if (isPrefix(pattern, word)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}