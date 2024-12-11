#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

char capitalToSmallLetter(char letter) {
    if (letter < 'A' || letter > 'Z') return letter;

    return letter - 'A' + 'a';
}

void sortCharacters(const char* str, char* result) {
    if (!str || !result) return;

    char letters[MAX_SIZE];
    int length = 0;

    while (*str != TERMINATE_SYMBOL) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
           letters[length] = capitalToSmallLetter(*str);
           length++;
        }

        str++;
    }

    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < length; j++) {
            if (letters[j] < letters[minIndex]) {
                minIndex = j;
            }
        }

        char temp = letters[i];
        letters[i] = letters[minIndex];
        letters[minIndex] = temp;
    }

    for (int i = 0; i < length; i++) {
        *result = letters[i];
        result++;
    }

    *result = TERMINATE_SYMBOL;
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    sortCharacters(str, result);
    cout << result << endl;
}