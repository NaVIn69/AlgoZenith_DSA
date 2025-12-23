#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure to represent an interval
struct Interval {
    int start;
    int end;
    int weight;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<pair<int,int>,int>> intervals(n);
    for (int i = 0; i < n; i++){
        cin >> intervals[i].first.first >> intervals[i].first.second >> intervals[i].second;
    }
    
    // Sort intervals based on end time.
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
        return a.end < b.end;
    });
     for (int i = 0; i < n; i++){
        cout<< intervals[i].start << intervals[i].end << intervals[i].weight<<endl;
    }
    // Prepare a DP table where dp[i] holds the maximum weight achievable using intervals[0..i]
    vector<int> dp(n, 0);
    dp[0] = intervals[0].weight;
    
    
    // Create a vector of end times for binary search
    vector<int> ends(n);
    for (int i = 0; i < n; i++){
        ends[i] = intervals[i].end;
    }
    
    // Process intervals from the second one onward.
    for (int i = 1; i < n; i++){
        // Option 1: Do not include the current interval.
        int option1 = dp[i-1];
        
        // Option 2: Include the current interval.
        int option2 = intervals[i].weight;
        
        // Find the last interval that ends at or before the current interval starts.
        // upper_bound gives the first index with value > intervals[i].start.
        int index = upper_bound(ends.begin(), ends.begin() + i, intervals[i].start) - ends.begin() - 1;
        if(index >= 0){
            option2 += dp[index];
        }
        cout<<option2<<endl;
        // Select the maximum of taking or not taking the current interval.
        dp[i] = max(option1, option2);
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    
    cout << dp[n-1] << "\n";
    
    return 0;
}
