#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int n;
vector<vector<int>>arr;
int dp[100100][3];
int rec(int level,int prev_index){
    // this function give me the maximum point from level.....n and we have been stored the prev_index in the prev_index
    if(level==n){
        return 0;
    }
    // cacheing
    if(dp[level][prev_index]!=-1){
        return dp[level][prev_index];
    }

    // choice
    // three choice
    int ans=-1;
    for(int j=0;j<3;j++){
        if(level==0||j!=prev_index){
         ans=max(ans,arr[level][j]+rec(level+1,j));
        }
    
    }
     dp[level][prev_index]=ans;
     return ans;
}
void solve(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i].push_back(a);
        arr[i].push_back(b);
        arr[i].push_back(c);
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


}
signed main(){
    solve();
}