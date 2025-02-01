#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;
const int DAYS = 0;
const int MONTS = 1;
const char SEPARATOR = '.';

int charToDigit(char s) {
    if (s < '0' || s > '9') {
        return s;
    }

    return s - '0';
}

int getMonthDays(int month) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return -1;
    }
}

int extractDateComponent(const char* str, int component) {
    if (!str) {
        return -1;
    }

    int position = 0;
    int target = 0;

    while (*str != TERMINATE_SYMBOL) {
        if (*str == SEPARATOR) {
            position++;
        } else {
            if (position == component) {
                target = (target * 10) + charToDigit(*str);
            } else if (position > component) {
                break;
            }
        }

        str++;
    }

    return target;
}

bool checkDate(const char* date) {
    if (!date) {
        return false;
    }

    int day = extractDateComponent(date, DAYS);
    int month = extractDateComponent(date, MONTS);

    int monthDays = getMonthDays(month);

    if (day > monthDays) {
        return false;
    }

    return true;
}

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << checkDate(str) << endl;

    return 0;
}