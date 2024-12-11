#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

unsigned int getDigitOccurencesCount(const char* str, char s) {
    if (!str) return 0;

    int count = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (*str == s) {
            count++;
        }

        str++;
    }

    return count;
}

char digitToChar(int d) {
    if (d < 0 || d > 9) return '0';

    return d + '0';
}

void intToCharArray(char* str, int num) {
    int i = 0;
    while (num != 0) {
        *str = digitToChar(num % 10);

        str++;
        num /= 10;
        i++;
    }

    char* start = str - i;
    char* end = str - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    str++;
    *str = TERMINATE_SYMBOL;
}

void getDigitOccurences(const char* digits, char* result) {
    for (int i = 0; i <= 9; i++) {
        int count = getDigitOccurencesCount(digits, digitToChar(i));
        char countStr[MAX_SIZE] = { '\0' };

        if (count != 0) {
            intToCharArray(countStr, count);

            char* ptr = countStr;

            while (*ptr != TERMINATE_SYMBOL) {
                *result = *ptr;

                result++;
                ptr++;
            }

            *result = 'x';
            result++;
            *result = digitToChar(i);
            result++;
            *result = ',';
            result++;
        }
    }
}

int main() {
    char digits[MAX_SIZE];
    char result[MAX_SIZE];
    cin.getline(digits, MAX_SIZE);

    getDigitOccurences(digits, result);

    cout << result << endl;
}