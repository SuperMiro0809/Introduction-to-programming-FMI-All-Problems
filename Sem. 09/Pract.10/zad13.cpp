#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

void insertSymbol(const char* text, char* result, char symbol, unsigned int idx) {
    if (!text || !result) return;

    int i = 0;
    while (*text != TERMINATE_SYMBOL) {
        if (i == idx) {
            *result = symbol;
            result++;
        }

        *result = *text;
        result++;
        text++;
        i++;
    }
}

int main() {
    char text[MAX_SIZE];
    char result[MAX_SIZE + 1];
    char symbol;
    int index;

    cin.getline(text, MAX_SIZE);
    cin >> symbol;
    cin >> index;

    insertSymbol(text, result, symbol, index);
    cout << result << endl;
}