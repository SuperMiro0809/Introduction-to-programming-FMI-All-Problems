#include <iostream>
using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_SIZE = 100;

int myStrCmp(const char* first, const char* second) {
    if (!first || !second) return 0;

    while(*first != TERMINATE_SYMBOL && *first == *second) {
        first++;
        second++;
    }

    return *first - *second;
}

int main() {
    char first[MAX_SIZE];
    char second[MAX_SIZE];

    cin.getline(first, MAX_SIZE);
    cin.getline(second, MAX_SIZE);

    int res = myStrCmp(first, second);

    cout << res << endl;
}