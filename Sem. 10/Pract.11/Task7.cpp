#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

char capitalToSmall(char s) {
    if (s < 'A' || s > 'Z') return s;

    return s - 'A' + 'a';
}

int countOccurances(const char* str, char s) {
    if (!str) return 0;

    int count = 0;

    while (*str != TERMINATE_SYMBOL) {
        if (capitalToSmall(*str) == s) {
            count++;
        }

        str++;
    }

    return count;
}

bool checkIfHasDuplicates(const char* str) {
    if (!str) return false;

    while (*str != TERMINATE_SYMBOL) {
        int count = countOccurances(str, capitalToSmall(*str));

        if (count > 1) return true;

        str++;
    }

    return false;
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    if (checkIfHasDuplicates(str)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}