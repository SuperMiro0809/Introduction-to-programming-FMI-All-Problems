#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

void myStrCpy(char* dest, const char* src) {
    while(*src != TERMINATE_SYMBOL) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = TERMINATE_SYMBOL;
}

int main() {
    char word[MAX_SIZE];
    char dest[MAX_SIZE];
    
    cin.getline(word, MAX_SIZE);

    myStrCpy(dest, word);

    cout << dest << endl;
}
