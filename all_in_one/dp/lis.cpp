#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[1001];
int rec(int level){
    // it give me best solution ending at index i
    //purining
    if(level<0){
        return 0;
    }

    // cache
    if(dp[level]!=-1){
        return dp[level];
    }
    int ans=1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }
    return dp[level]=ans;
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
 
  // here dp is going store the best lis ending at each index
  int best=0;
  for(int i=0;i<n;i++){
    best=max(best,rec(i));
  }
  cout<<best<<endl;

}
signed main(){
    solve();
}