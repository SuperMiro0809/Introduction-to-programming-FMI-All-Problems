#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    }

    return false;
}

bool checkIfDateIsValid(int day, int month, int year, bool isLeap) {
    if (day == 0 || day > 31) {
        cout << "Invalid date" << endl;
        return false;
    }
    if (month == 0 || month > 12) {
        return false;
    }
    if (month == 2 && day > 28 && !isLeap) {
        return false;
    }
    if (month == 2 && day > 29 && isLeap) {
        return false;
    }
    if (year == 0) {
        return false;
    }

    return true;
}

int main() {
    unsigned int day, month, year;
    cin >> day >> month >> year;

    bool isLeap = isLeapYear(year);

    if (!checkIfDateIsValid(day, month, year, isLeap)) {
        cout << "Invalid date" << endl;
        return 0;
    }

    day += 1;
    switch (month) {
        case 2:
            if (day > 28 && !isLeap) {
                day = 1;
                month++;
            } else if (day > 29 && isLeap) {
                day = 1;
                month++;
            }
        default:
            if (day > 31) {
                day = 1;
                month++;
            }
    }
    
    if (month > 12) {
        month = 1;
        year++;
    }

    cout << "Next day: " << day << " / " << month << " / " << year << endl;
}