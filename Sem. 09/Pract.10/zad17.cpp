#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_LETTERS = 1024;
const int MAX_WORDS = 100;
const int MAX_SIZE = 10000;
const char SPACE_CHARACTER = ' ';

void getWords(const char* str, char words[][MAX_LETTERS], int& wordsLength) {
    if (!str) return;

    int letterIndex = 0;
    bool wordBegin = false;

    while (*str != TERMINATE_SYMBOL) {
        if (*str == SPACE_CHARACTER) {
            if (wordBegin) {
                wordBegin = false;
                words[wordsLength][letterIndex] = TERMINATE_SYMBOL;

                wordsLength++;
                letterIndex = 0;
            }
        } else {
            wordBegin = true;

            words[wordsLength][letterIndex++] = *str;
        }

        str++;
    }

    if (wordBegin) {
        wordsLength++;
    }
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    char words[MAX_WORDS][MAX_LETTERS];
    int wordsLength = 0;

    getWords(str, words, wordsLength);

    for (int i = 0; i < wordsLength; i++) {
        cout << words[i] << endl;
    }
}