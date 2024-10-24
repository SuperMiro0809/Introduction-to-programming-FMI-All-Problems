#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num;
    cin >> num;

    bool isPrime = true;

    if (num == 1) {
        cout << "not prime" << endl;
        return 0;
    }

    // for (int i = 2; i <= num / 2; i++) {
    //     if (num % i == 0) {
    //         isPrime = false;
    //         break;
    //     }
    // }

    int sq = sqrt(num);
    for (int i = 2; i <= sq; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    cout << (isPrime ? "Prime" : "not prime") << endl;
}