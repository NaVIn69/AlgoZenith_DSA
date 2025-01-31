#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function with memoization to find the longest subsequence
int rec(int i, int N, int D, vector<int> &A, vector<int> &dp) {
    if (dp[i] != -1) return dp[i];  // Return memoized result if already computed

    int ans = 1;  // Start with a sequence length of 1 (just the element itself)
    
    // Try to extend the sequence backwards within the distance D
    for (int j = max(i - D, 0); j < i; j++) {
        if (A[j] < A[i]) {  // Ensure the increasing order condition
            ans = max(ans, 1 + rec(j, N, D, A, dp));  // Recur for j and update ans
        }
    }
    
    return dp[i] = ans;  // Store and return the result for dp[i]
}

// Main function to find the maximum result across all starting points
int invest(int N, int D, vector<int> &A) {
    int ans = 0;
    vector<int> dp(N, -1);  // DP array for memoization, initialized to -1
    
    for (int i = 0; i < N; i++) {
        ans = max(ans, rec(i, N, D, A, dp));  // Calculate the max result across all indices
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, D;
 vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int result = invest(N, D, A);
    cout << result << endl;

  
}