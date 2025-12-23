#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Use map to store max value for identical intervals
    map<pair<int, int>, int> interval_map;

    for (int i = 0; i < n; i++) {
        int start, end, val;
        cin >> start >> end >> val;
        pair<int, int> key = {start, end};
        if (interval_map.count(key))
            interval_map[key] = max(interval_map[key], val);
        else
            interval_map[key] = val;
    }

    // Convert map to vector and sort by end time
    vector<tuple<int, int, int>> intervals;
    for (auto &entry : interval_map) {
        intervals.push_back({entry.first.first, entry.first.second, entry.second});
    }

    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        return get<1>(a) < get<1>(b);  // sort by end time
    });

    // DP and Binary Search
    int sz = intervals.size();
    vector<int> dp(sz, 0);
    vector<int> ends(sz); // for binary search
    for (int i = 0; i < sz; ++i)
        ends[i] = get<1>(intervals[i]);

    for (int i = 0; i < sz; ++i) {
        int start = get<0>(intervals[i]);
        int val = get<2>(intervals[i]);

        // Find the last interval that ends before start
        int lo = 0, hi = i - 1, last = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ends[mid] <= start) {
                last = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

       dp[i] = max(dp[i - 1], val + dp[last]);  //

    }

    cout << dp[sz - 1] << endl;

    return 0;
}
