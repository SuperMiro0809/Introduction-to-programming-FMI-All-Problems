#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

int getLength(const char* str) {
    if (!str) return 0;

    int length = 0;
    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

int charToCountSystem(char s) {
    if (s >= 'A' && s <= 'Z') {
        return s - 'A' + 10;
    } else if (s >= '0' && s <= '9') {
        return s - '0';
    } else {
        return 0;
    }
}

int fromKToDecimal(const char* str, int k) {
    if (!str) return 0;

    int result = 0;
    int length = getLength(str);

    int multiplier = 1;

    const char* end = str + length - 1;

    while (str <= end) {
        result += multiplier * charToCountSystem(*end);

        end--;
        multiplier *= k;
    }

    return result;
}

int main() {
    char str[MAX_SIZE];
    int k;

    cin.getline(str, MAX_SIZE);
    cin >> k;

    cout << fromKToDecimal(str, k) << endl;
}