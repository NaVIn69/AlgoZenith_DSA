#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Trolley {
    int start, end, products;
};

// Sort first by end time; if equal, sort by start time
bool compareByEnd(const Trolley &a, const Trolley &b) {
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    
    // Use a map to store the maximum products for duplicate intervals
    map<pair<int, int>, int> trolley_map;
    for (int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        pair<int, int> key = {s, e};
        // If the key is not present or found, assign p; otherwise, update to the max
        if (trolley_map.find(key) == trolley_map.end())
            trolley_map[key] = p;
        else
            trolley_map[key] = max(trolley_map[key], p);
    }
    
    // Transfer map entries into a vector of Trolley structs
    vector<Trolley> trolleys;
    for (auto &entry : trolley_map) {
        trolleys.push_back({ entry.first.first, entry.first.second, entry.second });
    }
    
    // Sort the intervals by end time (with tie-breaker by start time)
    sort(trolleys.begin(), trolleys.end(), compareByEnd);
    
    int sz = trolleys.size();
    vector<int> dp(sz, 0);
    vector<int> ends(sz, 0);  // Auxiliary array for end times
    
    // Prepare a vector of end times for binary search use
    for (int i = 0; i < sz; i++) {
        ends[i] = trolleys[i].end;
    }
    
    // DP: dp[i] = max value achievable using intervals up to index i
    for (int i = 0; i < sz; i++) {
        int currStart = trolleys[i].start;
        int currProd = trolleys[i].products;
        
        // Find the rightmost interval that ends <= currStart using upper_bound
        int idx = upper_bound(ends.begin(), ends.begin() + i, currStart) - ends.begin() - 1;
        int include = currProd;
        if (idx >= 0)
            include += dp[idx];
        int exclude = (i > 0) ? dp[i - 1] : 0;
        dp[i] = max(include, exclude);
    }
    
    // (Optional) Uncomment the following to print the dp table for debugging:
    for (int i = 0; i < sz; i++) {
        cout << dp[i] << " ";
    }
    // cout << endl;
    
    cout << dp[sz - 1] << endl;
    
    return 0;
}
