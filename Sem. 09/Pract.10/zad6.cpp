#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

unsigned int getCharOccurencesCount(const char* str, char ch) {
    if (!str) return 0;

    unsigned count = 0;

    while (*str != TERMINATE_SYMBOL) {
        if (*str == ch) {
            count++;
        }

        str++;
    }

    return count;
}

int main() {
    char str[MAX_SIZE];
    char ch;

    cin.getline(str, MAX_SIZE);
    cin >> ch;

    cout << getCharOccurencesCount(str, ch) << endl;
}