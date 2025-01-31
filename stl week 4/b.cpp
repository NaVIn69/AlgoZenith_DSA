
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of stable dishes Shakish can carry
int maxStableDishes(vector<int>& dishes) {
    int N = dishes.size();
    if (N == 0) return 0;

    // DP array to store the length of the longest non-decreasing subsequence ending at each index
    vector<int> dp(N, 1);

    // Iterate over all pairs of indices (i, j) with i < j
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dishes[j] <= dishes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The maximum value in dp array is the result
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    cin >> N;
    vector<int> dishes(N);
    for (int i = 0; i < N; ++i) {
        cin >> dishes[i];
    }

    int result = maxStableDishes(dishes);
    cout << result << endl;

    return 0;
}
