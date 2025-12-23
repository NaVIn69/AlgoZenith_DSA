#include<bits/stdc++.h>

using namespace std;

// Helper function to count subarrays with at most K unique elements
int atMostK(const vector<int>& arr, int K) {
    unordered_map<int, int> freq;
    int left = 0, right = 0, count = 0;

    while (right < arr.size()) {
        freq[arr[right]]++;
        while (freq.size() > K) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                freq.erase(arr[left]);
            left++;
        }
        count += (right - left + 1);
        right++;
    }
    return count;
}

int countExactK(const vector<int>& arr, int K) {
    return atMostK(arr, K) - atMostK(arr, K - 1);
}

int main() {
    int n, k;
    cin >> n;
    vector<int> genreList(n);
    for (int i = 0; i < n; ++i) {
        cin >> genreList[i];
    }
    cin >> k;

    int result = countExactK(genreList, k);
    cout << result << endl;
    return 0;
}
