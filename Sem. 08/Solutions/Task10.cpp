#include <iostream>
using namespace std;

const char* daysOfWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

bool checkBit(int n, int k) {
    int mask = 1;
    mask <<= k;

    return (mask & n) == mask;
}

int main() {
    uint8_t controlDays = 105;

    for (int i = 0; i < 7; i++) {
        if (checkBit(controlDays, i)) {
            cout << daysOfWeek[i] << ", ";
        }
    }

    cout << endl;
    return 0;
}