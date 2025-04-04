#include <iostream>
#include <vector>

using namespace std;

int maxSubarraysWithZero( vector<int>& arr) {

    int left = 0, right = 0, maxCount = 0;
    int n = arr.size();
    //  int n = arr.size();
    // int maxCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            arr[i] = 0;
            break;
        }
    }
    
    while (right < n) {
        if (arr[right] == 0) {
            maxCount += right - left + 1;
        } else {
            left = right + 1;
        }
        right++;
    }
    
    return maxCount;
}

int main() {
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   cout<<maxSubarraysWithZero(v)<<endl;
}