#include <iostream>
using namespace std;

void getLastShow(int n, unsigned int& maxHours, unsigned int& maxMins) {
    int hours, mins, duration;

    for (int i = 0; i < n; i++) {
        cin >> hours >> mins >> duration;

        int durationH = duration / 60;
        int durationMins = duration - (durationH * 60);

        int sumMins = mins + durationMins;
        int endM = sumMins % 60;
        int endH = hours + durationH + (sumMins / 60);

        if (endH > maxHours) {
            maxHours = endH;
            maxMins = endM;
        }
    }
}

int main() {
    int n;
    cin >> n;

    unsigned int maxHours = 0;
    unsigned int maxMins = 0;

    getLastShow(n, maxHours, maxMins);

    cout << maxHours << " " << maxMins << endl;
}