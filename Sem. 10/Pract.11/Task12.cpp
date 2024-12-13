#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;
const int WORDS = 3;

void enterWords(char words[][MAX_SIZE]) {
    for (int i = 0; i < WORDS; i++) {
        cin.getline(words[i], MAX_SIZE);
    }
}

void fillPrefixes(const char* start, const char* end, char allPrefixes[][MAX_SIZE], int length) {
    if (!start || !end) return;

    int index = 0;
    while (start <= end) {
        allPrefixes[length][index++] = *start;
        start++;
    }

    allPrefixes[length][index] = TERMINATE_SYMBOL;
}

void findPrefixes(const char* str, char allPrefixes[][MAX_SIZE], int& length) {
    if (!str) return;

    const char* start = str;

    while (*str != TERMINATE_SYMBOL) {
        fillPrefixes(start, str, allPrefixes, length);
        length++;
        str++;
    }
}

bool checkIfPrefix(const char* str, const char* prefix) {
    if (!str || !prefix) return false;

    while (*prefix != TERMINATE_SYMBOL) {
        if (*prefix != *str) {
            return false;
        }

        str++;
        prefix++;
    }

    return true;
}

void findLongestPrefix(const char* first, const char* second, char* maxPrefix, const char allPrefixes[][MAX_SIZE], int length) {
    if (!first || !second || !maxPrefix) return;

    int maxLength = 0;

    for (int i = 0; i < length; i++) {
        if (checkIfPrefix(first, allPrefixes[i]) && checkIfPrefix(second, allPrefixes[i])) {
            maxLength++;
            for (int j = 0; j < maxLength; j++) {
                maxPrefix[j] = allPrefixes[i][j];
            }

            maxPrefix[maxLength] = TERMINATE_SYMBOL;
        }
    }

    if (maxLength == 0) {
        maxPrefix[maxLength] = TERMINATE_SYMBOL;
    }
}

int main() {
    char words[WORDS][MAX_SIZE];
    enterWords(words);
    
    char allPrefixes[MAX_SIZE][MAX_SIZE];
    int length = 0;
    findPrefixes(words[0], allPrefixes, length);

    char maxPrefix[MAX_SIZE];

    findLongestPrefix(words[1], words[2], maxPrefix, allPrefixes, length);
    cout << maxPrefix << endl;
}