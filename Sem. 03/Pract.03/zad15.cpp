#include <iostream>
using namespace std;

int main() {
    int k, num;
    cin >> k;

    int br = 0, digits = 0;
    int copyK = k;

    while (copyK != 0) {
        digits++;
        copyK /= 10;
    }

    cin >> num;
    while (num != 0) {
        int suf = 0;

        for (int i = 1; i <= digits; i++) {
            int multiplier = 1;
            for (int j = 0; j < i; j++) {
                multiplier *= 10;
            }

            suf = k % multiplier;

            if (num == suf) {
                br++;
                break;
            }
        }

        cin >> num;
    }

    cout << br << endl;;

    return 0;
}