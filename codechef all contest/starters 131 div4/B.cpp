#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& A, int K, int mid) {
    int n = A.size();
    int left = A[0] + K;
    int right = A[0] - K;

    for (int i = 1; i < n; ++i) {
        int low = A[i] - mid;
        int high = A[i] + mid;

        if (low > right + K || high < left - K) {
            return false;
        }

        left = max(left, low + K);
        right = min(right, high - K);
    }

    return true;
}

int minDifference(vector<int>& A, int K) {
    int low = 0, high = 1e9, result = high;

    sort(A.begin(), A.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(A, K, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin>>t;
    while(t--){
    int N, K;
    //cout << "Enter the length of the array: ";
    cin >> N;
   // cout << "Enter the value of K: ";
    cin >> K;

    vector<int> A(N);
    //cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = minDifference(A, K);
    cout  << result << endl;
    }

    return 0;
}
