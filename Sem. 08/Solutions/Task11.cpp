#include <iostream>
using namespace std;

void convertToIpAddress(uint32_t ip) {
    uint8_t a = (ip >> 24) & 0xFF;
    uint8_t b = (ip >> 16) & 0xFF;
    uint8_t c = (ip >> 8) & 0xFF;
    uint8_t d = ip & 0xFF;

    cout << (int)a << '.' << (int)b << '.' << (int)c << '.' << (int)d << endl;
}

int main() {
    uint32_t ip = 2155905152;

    convertToIpAddress(ip);
}