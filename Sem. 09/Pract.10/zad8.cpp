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

bool searchInText(const char* text, const char* pattern) {
    if (!text || !pattern) return 0;

    while (*text != TERMINATE_SYMBOL) {
        if (isPrefix(pattern, text)) {
            return true;
        }

        text++;
    }
    
    return false;
}

int main() {
    char text[MAX_SIZE];
    char pattern[MAX_SIZE];

    cin.getline(text, MAX_SIZE);
    cin.getline(pattern, MAX_SIZE);

    if (searchInText(text, pattern)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}