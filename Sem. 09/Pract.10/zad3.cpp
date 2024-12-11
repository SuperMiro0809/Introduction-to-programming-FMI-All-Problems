#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

unsigned int myStrLen(const char* str) {
    unsigned length = 0;

    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

void myStrCpy(char* dest, const char* src) {
    while(*src != TERMINATE_SYMBOL) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = TERMINATE_SYMBOL;
}

void myStrCat(char* first, const char* second) {
    if (!first || !second) return;

    unsigned firstLength = myStrLen(first);
    first += firstLength;
    
    myStrCpy(first, second);
}

int main() {
    char first[MAX_SIZE];
    char second[MAX_SIZE];

    cin.getline(first, MAX_SIZE);
    cin.getline(second, MAX_SIZE);

    myStrCat(first, second);

    cout << first << endl;
}