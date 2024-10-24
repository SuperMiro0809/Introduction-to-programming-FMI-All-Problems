#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Its even";
    }

    // 3 -> 5  2
    // 5 -> 9  4
    // 9 -> 17 8

    int lines =  n + n - 1;
    int halfLines = lines / 2;

    // First Line
    for (int j = 0; j < (lines - n) / 2; j++) {
        cout << "." << " ";
    }

    for (int j = 0; j < n; j++) {
        cout << "#" << " ";
    }

    for (int j = 0; j < (lines - n) / 2; j++) {
        cout << "." << " ";
    }

    cout << endl;

    // Next Lines
    for (int i = 1; i < halfLines; i++) {
        for (int j = 0; j < (lines - n) / 2; j++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

        for (int j = 0; j < n - 2; j++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

            for (int j = 0; j < (lines - n) / 2; j++) {
            cout << "." << " ";
        }

        cout << endl;
    }

    // Middle Line
    for (int j = 0; j < n / 2 + 1; j++) {
        cout << "#" << " ";
    }

    for (int j = 0; j < lines - n - 1; j++) {
        cout << "." << " ";
    }

    for (int j = 0; j < n / 2 + 1; j++) {
        cout << "#" << " ";
    }

    cout << endl;

    // Next Lines
    for (int i = 1; i < halfLines; i++) {
        for (int k = 0; k < i; k++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

        for (int k = 0; k < lines - 2 - i * 2; k++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

        for (int k = 0; k < i; k++) {
            cout << "." << " ";
        }

        cout << endl;
    }

    // End Line
    for(int i = 0; i < n - 1; i++) {
        cout << "." << " ";
    }

    cout << "#" << " ";

    for(int i = 0; i < n - 1; i++) {
        cout << "." << " ";
    }

    cout << endl;
}