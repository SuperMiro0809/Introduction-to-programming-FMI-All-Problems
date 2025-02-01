#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }

        return true;
    }

    return false;
}

void printLeapYear(int year, int n) {
    if (n == 0) {
        return;
    }

    if (isLeapYear(year)) {
        cout << year << endl;
        printLeapYear(year + 1, n - 1);
    } else {
        printLeapYear(year + 1, n);
    }
}

int main() {
    int n;
    cin >> n;

    int currentYear = 2025;
    printLeapYear(currentYear, n);
    return 0;
}