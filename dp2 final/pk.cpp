
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a TV show interval
struct Interval {
    int start; // Start time in minutes (e.g., 10:00 AM = 600 minutes)
    int end;   // End time in minutes (e.g., 10:30 AM = 630 minutes)
};

// Comparator to sort intervals by start time
bool compareIntervals(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

// Function to check if Bob can spend exactly M minutes watching TV shows
bool canSpendTime(int M, vector<Interval> &intervals) {
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end(), compareIntervals);

    int totalTime = 0;
    for (const auto &interval : intervals) {
        if (totalTime >= M) break; // If we've already reached M, stop

        // Add the duration of the current interval to the total time
        int duration = interval.end - interval.start;
        totalTime += duration;

        // If totalTime exceeds M, adjust by subtracting the excess
        if (totalTime > M) {
            totalTime -= (totalTime - M);
        }
    }

    // Check if the total time equals M
    return totalTime == M;
}

int main() {
   int n,m;
   cin>>n>>m;
   vector<Interval>v;
   for(int i=0;i<n;i++){
      int d, st1,st2,st3;
      cin>>d>>st1>>st2>>st3;
      v.push
   }

    return 0;
}