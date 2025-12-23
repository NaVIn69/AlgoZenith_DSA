#include <bits/stdc++.h>
using namespace std;

int longest(vector<int>& arr, vector<int>& brr) {
    unordered_map<int,int> bestA, bestB;

    // longest streaks in arr
    int cnt = 1;
    for (int i=1; i<(int)arr.size(); i++) {
        if (arr[i]==arr[i-1]) cnt++;
        else {
            bestA[arr[i-1]] = max(bestA[arr[i-1]], cnt);
            cnt = 1;
        }
    }
    bestA[arr.back()] = max(bestA[arr.back()], cnt);

    // longest streaks in brr
    cnt = 1;
    for (int i=1; i<(int)brr.size(); i++) {
        if (brr[i]==brr[i-1]) cnt++;
        else {
            bestB[brr[i-1]] = max(bestB[brr[i-1]], cnt);
            cnt = 1;
        }
    }
    bestB[brr.back()] = max(bestB[brr.back()], cnt);

    // here wew have to check in both may be some element in b but not in a which give us maximum subarray of continous element
    int ans = 0;
    for (auto &[val,len]: bestA) ans = max(ans, len + bestB[val]);
    for (auto &[val,len]: bestB) ans = max(ans, len + bestA[val]);

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n), brr(n);
    for (int i=0;i<n;i++) cin >> arr[i];
    for (int i=0;i<n;i++) cin >> brr[i];

    cout << longest(arr,brr) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}
