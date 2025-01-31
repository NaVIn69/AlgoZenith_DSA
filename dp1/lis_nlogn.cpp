// Binary Search Approach of Finding LIS by
// reducing the problem to longest
// common Subsequence
#include <bits/stdc++.h>
using namespace std;

int miniDeletions(vector<int>& arr)
{

    int n = arr.size();
    vector<int> ans;

    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {

      
            ans.push_back(arr[i]);
        }
        else {

          
            int low = lower_bound(ans.begin(), ans.end(),
                                  arr[i])
                      - ans.begin();

            ans[low] = arr[i];
        }
    }

    
   int k=arr.size()-ans.size();
   if(k>1){
    return k-1;
   }
   return 0;
}

// Driver program to test above function
int main()
{
    int n;
    cin>>n;

   vector<int>nums;
   nums.resize(n);
   for(int i=0;i<n;i++){
    cin>>nums[i];
   }
    // Function call
    cout<<miniDeletions(nums)<<endl;
    return 0;
}