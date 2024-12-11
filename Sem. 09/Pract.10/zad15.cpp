#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const char SPACE_CHARACTER = ' ';
const int MAX_SIZE = 100;

unsigned int getWordsCount(const char* words) {
    if (!words) return 0;

    int count = 0;
    bool wordBegin = false;
    while (*words != TERMINATE_SYMBOL) {
        if (*words == SPACE_CHARACTER) {
            if (wordBegin) {
                wordBegin = false;
                count++;
            }
        } else {
            wordBegin = true;
        }

        words++;
    }

    if (wordBegin) {
        count++;
    }

    return count;
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << getWordsCount(str) << endl;
}