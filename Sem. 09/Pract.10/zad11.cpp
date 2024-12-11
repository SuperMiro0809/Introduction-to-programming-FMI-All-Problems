#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

unsigned int getLength(const char* str) {
    if (!str) return 0;

    unsigned count = 0;

    while (*str != TERMINATE_SYMBOL) {
        count++;
        str++;
    }

    return count;
}

bool isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str + getLength(str) - 1;

    while (start < end) {
        if (*start != *end) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    char word[MAX_SIZE];
    cin.getline(word, MAX_SIZE);

    if (isPalindrome(word)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}