#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[1000005];

vector<pair<int,int>> solveWindow(int k) {
    unordered_map<int,int> freq;

    vector<pair<int,int>> ans;  // {min_operations, best_value}

    int head = -1, tail = 0;

    long long maxFreq = 0;
    long long bestVal = 0;

    while (tail < n) {

        // extend window
        while (head + 1 < n && (head - tail + 2) <= k) {

            head++;
            int x = arr[head];

            freq[x]++;

            // update mode
            if (freq[x] > maxFreq || (freq[x] == maxFreq && x < bestVal)) {
                maxFreq = freq[x];
                bestVal = x;
            }
        }

        // window size must be exactly k
        if (head - tail + 1 == k) {
            int min_ops = k - maxFreq;
            ans.push_back({min_ops, bestVal});
        }

        // shrink window
        int rem = arr[tail];
        freq[rem]--;

        if (rem == bestVal && freq[rem] < maxFreq) {
            // must recompute maxFreq + bestVal
            maxFreq = 0;
            bestVal = LLONG_MAX;

            for (auto &p : freq) {
                if (p.second > maxFreq || (p.second == maxFreq && p.first < bestVal)) {
                    maxFreq = p.second;
                    bestVal = p.first;
                }
            }
        }

        tail++;

        if (tail > head) {
            head = tail - 1;
            freq.clear();
            maxFreq = 0;
            bestVal = 0;
        }
    }

    return ans;
}

void solve(){
    int k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto res = solveWindow(k);

    for (auto &p : res) {
        cout << p.first << " " << p.second << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;   // uncomment only if multiple testcases exist
    while (t--) solve();
}
