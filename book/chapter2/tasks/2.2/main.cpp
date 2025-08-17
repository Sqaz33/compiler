#include <climits>
#include <iostream>

int bit_scan_reverse(unsigned n) {
    int bitsize = sizeof(n) * CHAR_BIT;
    for (int i = 0; i < bitsize; ++i) {
        int idx = bitsize - i - 1;
        if ((n >> idx) & 1)
            return idx; 
    }
    return bitsize;
}

int bit_scan(unsigned n) {
    int bitsize = sizeof(n) * CHAR_BIT;
    int last = bitsize;
    for (int i = 0; i < bitsize; ++i) {
        if ((n >> i) & 1)
            last = i;
    }
    return last;
}

int main() {
    std::cout << bit_scan_reverse(10) 
              << '\n'
              << bit_scan(10)
              << '\n';
}

// для обратного -> (bitsize + 1) / 2
// для прямого -> 32

