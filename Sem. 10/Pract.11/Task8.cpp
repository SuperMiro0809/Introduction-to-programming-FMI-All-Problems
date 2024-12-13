#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

char capitalToSmall(char s) {
    if (s < 'A' || s > 'Z') return s;

    return s - 'A' + 'a';
}

void fillLetters(const char* str, char* result) {
    if (!str || !result) return;

    while (*str != TERMINATE_SYMBOL) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            *result = capitalToSmall(*str);
            result++;
        }

        str++;
    }

    *result = TERMINATE_SYMBOL;
}

void sortLetters(char* result) {
    if (!result) return;

    while (*result != TERMINATE_SYMBOL) {
        char* minIndex = result;
        char *next = result + 1;

        while (*next != TERMINATE_SYMBOL) {
            if (*next < *minIndex) {
                minIndex = next;
            }

            next++;
        }

        if (minIndex != result) {
            char temp = *result;
            *result = *minIndex;
            *minIndex = temp;
        }

        result++;
    }
}

void sortCharacters(const char* str, char* result) {
    if (!str || !result) return;

    fillLetters(str, result);
    sortLetters(result);
}

int main() {
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    sortCharacters(str, result);

    cout << result << endl;
}