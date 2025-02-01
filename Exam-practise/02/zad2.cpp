#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int DAY = 0;
const int MONTH = 1;
const int YEAR = 2;
const char SEPARATOR = '-';
const char TERMINATE_SYMBOL = '\0';

int charToDigit(char s);

bool isLeapYear(int year);

int extraxtDateComponent(const char* date, int component);

int getMonthDays(int month, bool leapYear);

bool validDate(const char* date);

int main() {
    char date[MAX_SIZE];
    cin.getline(date, MAX_SIZE);

    cout << validDate(date) << endl;
    return 0;
}

int charToDigit(char s) {
    if (s < '0' || s > '9') {
        return -1;
    }

    return s - '0';
}

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }

        return true;
    }

    return false;
}

int extraxtDateComponent(const char* date, int component) {
    if (!date) {
        return 0;
    }

    int result = 0;
    int position = 0;

    while (*date != TERMINATE_SYMBOL) {
        if (*date == SEPARATOR) {
            position++;
        } else {
            if (position == component) {
                int number = charToDigit(*date);

                if (number == -1) {
                    return -1;
                }

                result = (result * 10) + number;
            } else if (position > component) {
                break;
            }
        }

        date++;
    }

    return result;
}

int getMonthDays(int month, bool leapYear) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            return leapYear ? 29 : 28;
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

bool validDate(const char* date) {
    if (!date) {
        return false;
    }

    int day = extraxtDateComponent(date, DAY);
    int month = extraxtDateComponent(date, MONTH);
    int year = extraxtDateComponent(date, YEAR);

    if (day == -1 || month == -1 || year == -1) {
        return false;
    }

    bool leapYear = isLeapYear(year);

    int monthDays = getMonthDays(month, leapYear);

    if (day > monthDays) {
        return false;
    }

    return true;
}