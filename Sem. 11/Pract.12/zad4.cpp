#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const char TERMINATE_SYMBOL = '\0';

int getLength(const char* str);

char* getPrefix(const char* str, int length);

char* getSufix(const char* str, int length);

char** getPrefixes(const char* str, int prefixesLength);

char** getSufixes(const char* str, int sufixesLength);

int main() {
    char str[MAX_SIZE];

    cin.getline(str, MAX_SIZE);

    int length = getLength(str);
    int prefixesLength = length + 1;
    char** prefixes = getPrefixes(str, prefixesLength);

    int sufixesLength = length + 1;
    char** sufixes = getSufixes(str, sufixesLength);

    for (int i = 0; i < prefixesLength; i++) {
        cout << prefixes[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < sufixesLength; i++) {
        cout << sufixes[i] << endl;
    }

    for (int i = 0; i < prefixesLength; i++) {
        delete[] prefixes[i];
    }
    delete[] prefixes;

    for (int i = 0; i < sufixesLength; i++) {
        delete[] sufixes[i];
    }
    delete[] sufixes;

    return 0;
}

int getLength(const char* str) {
    if (!str) {
        return 0;
    }

    int length = 0;
    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

char* getPrefix(const char* str, int length) {
    if (!str) {
        return nullptr;
    }

    char* result = new char[length + 1];

    int i = 0;
    while (i < length) {
        result[i++] = *str;
        str++;
    }

    result[i] = TERMINATE_SYMBOL;

    return result;
}

char* getSufix(const char* str, int length) {
    if (!str) {
        return nullptr;
    }

    char* result = new char[length + 1];
    const char* end = str + getLength(str) - 1;

    int i = 0;
    while (i < length) {
        result[i++] = *end;
        end--;
    }

    result[i] = TERMINATE_SYMBOL;

    return result;
}

char** getPrefixes(const char* str, int prefixesLength) {
    if (!str) {
        return nullptr;
    }
    
    char** prefixes = new char* [prefixesLength];

    for (int i = 0; i < prefixesLength; i++) {
        prefixes[i] = getPrefix(str, i);
    }

    return prefixes;
}

char** getSufixes(const char* str, int sufixesLength) {
    if (!str) {
        return nullptr;
    }

    char** sufixes = new char* [sufixesLength];

    for (int i = 0; i < sufixesLength; i++) {
        sufixes[i] = getSufix(str, i);
    }

    return sufixes;
}
