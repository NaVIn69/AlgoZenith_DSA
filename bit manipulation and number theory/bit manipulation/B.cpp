#include <iostream>

int biggestPowerOf2(int n) {
    if (n == 0) {
        return -1; // Special case when n is 0
    }
    
    int count = 0;
    while ((n & 1) == 0) { // Continue right-shifting until n is odd
        n >>= 1;
        count++;
    }

    return 1 << count; // The largest power of 2 is 2^count
}

int main() {
    int n = -2; // Replace with your input value
    int result = biggestPowerOf2(n);
    std::cout << "The biggest power of 2 that divides " << n << " is: " << result << std::endl;
    return 0;
}
