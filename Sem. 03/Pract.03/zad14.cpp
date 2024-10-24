#include <iostream>

using namespace std;

int main() {
    int N, num;
    cin >> N;

    int sum = 0;
    int maxEl = INT_MIN;
    bool hasSum = false;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num > maxEl) {
            maxEl = num;
        }
    }

    return 0;
}