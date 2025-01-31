#include <bits/stdc++.h>
using namespace std;

long totalTriplets(vector<int> capacity, long desiredCapacity) {
    int n = capacity.size();
    long count = 0;
    
    // Sort the array to apply two-pointer approach
    sort(capacity.begin(), capacity.end());
    
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            long sum = capacity[i] + capacity[left] + capacity[right];
            
            if (sum == desiredCapacity) {
                count++;
                left++;
                right--;
            } else if (sum < desiredCapacity) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return count;
}
int main() {
    vector<int> capacity = {1, 2, 2, 2, 4};
    long desiredCapacity = 8;
    cout << totalTriplets(capacity, desiredCapacity) << endl;
    
}

