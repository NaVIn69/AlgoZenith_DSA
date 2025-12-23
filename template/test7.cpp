#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to find the sum of smallest Kth   values in a subarray
int sum_of_smallest_k(vector<int>& arr, int K) {
    if (K == 0) return 0;
    priority_queue<int> max_heap;
    for (int num : arr) {
        max_heap.push(num);
        if (max_heap.size() > K) {
            max_heap.pop();
        }
    }
    int sum = 0;
    while (!max_heap.empty()) {
        sum += max_heap.top();
        max_heap.pop();
    }
    return sum;
}

int max_return(int N, int C, vector<int>& A) {
    vector<int> dp(N + 1, 0);
    
    for (int i = 1; i <= N; ++i) {
        priority_queue<int> min_heap;
        for (int j = i; j > 0; --j) {
            min_heap.push(A[j-1]);
            if (min_heap.size() > C) {
                min_heap.pop();
            }
            int M = i - j + 1;
            int K = M / C;
            vector<int> smallest_elements;
            priority_queue<int> temp_heap = min_heap;
            while (!temp_heap.empty()) {
                smallest_elements.push_back(temp_heap.top());
                temp_heap.pop();
            }
            sort(smallest_elements.begin(), smallest_elements.end());
            int current_sum = sum_of_smallest_k(smallest_elements, K);
            dp[i] = max(dp[i], dp[j-1] + current_sum);
        }
    }
    
    return dp[N];
}

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << max_return(N, C, A) << endl;

    return 0;
}
