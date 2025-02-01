#include <iostream>
using namespace std;

const int NUMBER_ONE = 0;
const int NUMBER_TWO = 1;
const char TERMINATE_SYMBOL = '\0';

char digitToChar(int d);

void enterArray(long* arr, size_t n);

long* findTwoSmallDifNumbers(const long* arr, size_t n);

int getNumberLength(long number);

int* getDigitsArr(long number, int& digits);

int findStringLength(const long* numbers);

void appendNumberToString(char* str, long number, int& index);

char* findDiff(const long* arr, size_t n);

int main() {
    size_t n;
    cin >> n;

    long* arr = new long[n];
    enterArray(arr, n);

    char* result = findDiff(arr, n);

    cout << result << endl;

    delete[] result;
    delete[] arr;
    return 0;
}

char digitToChar(int d) {
    if (d < 0 || d > 9) {
        return '0';
    }

    return d + '0';
}

void enterArray(long* arr, size_t n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

long* findTwoSmallDifNumbers(const long* arr, size_t n) {
    if (!arr) {
        return nullptr;
    }

    long* result = new long[2];
    int smallestDif = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = arr[i] - arr[j];

            if (diff < 0) {
                diff *= -1;
            }

            if (smallestDif > diff) {
                smallestDif = diff;
                result[NUMBER_ONE] = arr[i] > arr[j] ? arr[i] : arr[j];
                result[NUMBER_TWO] = arr[i] < arr[j] ? arr[i] : arr[j];
            }
        }
    }

    return result;
}

int getNumberLength(long number) {
    int length = 0;

    while (number != 0) {
        length++;
        number /= 10;
    }

    return length;
}

int* getDigitsArr(long number, int& digits) {
    int numberCopy = number;

    while (numberCopy != 0) {
        digits++;
        numberCopy /= 10;
    }
    
    int* digitsArr = new int[digits];
    int index = 0;

    while (number != 0) {
        digitsArr[index++] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < digits / 2; i++) {
        int temp = digitsArr[i];
        digitsArr[i] = digitsArr[digits - i - 1];
        digitsArr[digits - i - 1] = temp;
    }

    return digitsArr;
}

int findStringLength(const long* numbers) {
    if (!numbers) {
        return 0;
    }

    int length = getNumberLength(numbers[NUMBER_ONE]) + getNumberLength(numbers[NUMBER_TWO]);
    length += 2; // for separator and terminate symbol

    return length;
}

void appendNumberToString(char* str, long number, int& index) {
    if (!str) {
        return;
    }

    int digits = 0;
    int* digitsArr = getDigitsArr(number, digits);

    for (int i = 0; i < digits; i++) {
        str[index++] = digitToChar(digitsArr[i]);
    }
}

char* findDiff(const long* arr, size_t n) {
    if (!arr) {
        return nullptr;
    }

    long* numbers = findTwoSmallDifNumbers(arr, n);
    int length = findStringLength(numbers);

    char* result = new char[length];
    int index = 0;
    
    appendNumberToString(result, numbers[NUMBER_ONE], index);
    result[index++] = ',';
    appendNumberToString(result, numbers[NUMBER_TWO], index);
    result[index] = TERMINATE_SYMBOL;

    delete[] numbers;
    return result;
}
