#include<bits/stdc++.h>
using namespace std;


// fn -> it gives me total number subset to achieve target by selecting (0...level) element 
int rec(int level,int target,vector<int>&arr,vector<vector<int>>&dp){
    // purning
    if(level<0){
        return 0;
    }
    // base case
    if(level==0){
        if(target==0&&arr[0]==0){
            return 2; // 2 ways
        }
        if(target==arr[0]||target==0){
            return 1;
        }
        return 0;
    }
    // cache
    if(dp[level][target]!=-1){
        return dp[level][target];
    }


    int nottake=rec(level-1,target,arr,dp);
    int taken=0;
    if(arr[level]<=target){
        taken=rec(level-1,target-arr[level],arr,dp);
    }
    return dp[level][target]=taken+nottake;
}


void solve(){
  int n,t;
  cin>>n>>t;
  vector<int>arr(n);
  int tot=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    tot+=arr[i];
  }   
  if(t>tot) return ;
  vector<vector<int>>dp(n+1,vector<int>(tot+6,-1));
  for(int i=1;i<=t;i++){
    int x= rec(n-1,i,arr,dp);
  }
  // this give me total number way to achieve the {1....t} target by selecting index {0....n-1}
  for(int i=0;i<n;i++){
    for(int j=1;j<=t;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
//   cout<<cnt<<endl;

}
int main(){
    solve();
}