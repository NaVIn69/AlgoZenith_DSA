#include <iostream>
#include <string>
using namespace std;

int totalEnergy(string& s, int k) {
    int n = s.size();
    int total_energy = 0;

    // Calculate the energy for the first window of size k
    int current_energy = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] != s[i + 1]) {
            ++current_energy;
        }
    }

    total_energy += current_energy;

    // Slide the window across the string
    for (int i = 1; i <= n - k - 1; ++i) {
        // Subtract the transition that is leaving the window
        if (s[i - 1] != s[i]) {
            --current_energy;
        }
        // Add the transition that is entering the window
        if (s[i + k - 1] != s[i + k]) {
            ++current_energy;
        }
        total_energy += current_energy;
    }

    return total_energy;
}

int main() {
    std::string s;
    int k;

    std::cout << "Enter the string S: ";
    std::cin >> s;
    std::cout << "Enter the integer K: ";
    std::cin >> k;

    if (k > s.size()) {
        std::cerr << "Error: K must be less than or equal to the length of the string." << std::endl;
        return 1;
    }

    int result = totalEnergy(s, k);
    std::cout << "Total transition energy: " << result << std::endl;

    return 0;
}