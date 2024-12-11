#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';

unsigned int myStrLen(const char* str) {
    unsigned length = 0;

    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

int main() {
    char word[100];
    cin.getline(word, 100);

    cout << myStrLen(word) << endl;
}