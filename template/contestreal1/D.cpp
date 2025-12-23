#include <iostream>
#include <vector>

using namespace std;

bool canConstructSpecialTriangle(int h, const vector<int>& numbers) {
    int n = h * (h + 1) / 2;

    // Check if the given numbers can construct a Special Triangle
    int index = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= i; ++j) {
            // Check if the current element is less than the two numbers just below it
            if (j < i && numbers[index] >= numbers[index + i] && numbers[index] >= numbers[index + i + 1]) {
                return false;
            }
            // Move to the next number in the array
            ++index;
        }
    }

    return true;
}

int main() {
    int h;
    cin >> h;

    vector<int> numbers(h * (h + 1) / 2);
    for (int i = 0; i < h * (h + 1) / 2; ++i) {
        cin >> numbers[i];
    }

    // Check if a Special Triangle can be constructed
    if (canConstructSpecialTriangle(h, numbers)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
