#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int bigger =  a > b ? a : b;

    // for (int i = bigger; i <= a * b; i++) {
    //     if (i % a == 0 && i % b == 0) {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    for (int i = bigger; ; i+=bigger) {
        if (i % a == 0 && i % b == 0) {
            cout << i << endl;
            break;
        }
    }
}