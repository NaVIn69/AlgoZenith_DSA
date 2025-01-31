#include<bits/stdc++.h>
using namespace std;

int invest(int N, int D, vector<int>& A) {
    vector<int> dp(N + 1, 1);
    dp[0] = 1; 

    for (int i = 0; i < N; ++i) {
        for (int j=max(0,i-D);j<i;j++) {
            if (A[i] > A[j]) { 
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans=1;
    for(int i=0;i< N;i++){
        ans=max(ans,dp[i]);
    }
 return ans;
}
int main(){
    int k,n;
    cin>>k>>n;
  vector<int>arr(k);
  vector<int>brr(n);
  for(int i=0;i<n;i++){
    cin>>brr[i];
  }
  for(int i=0;i<k;i++){
    cin>>arr[i];
  }
  cout<<invest(n,k,brr)<<endl;
}