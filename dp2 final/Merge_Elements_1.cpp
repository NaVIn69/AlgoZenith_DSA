#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[501];
int dp[501][501];
int prefix[501];
int rec(int l,int r){
    // this function gives me the mini cost to merge all element from l to r
    if(l==r){
        return 0;
        // here we can not merge the single ele
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int ans=1e9;
    for(int mid=l;mid<r;mid++){
        int left_sum=(l==0)?prefix[mid]%100:prefix[mid]%100-prefix[l-1]%100;
        int right_sum=prefix[r]%100-prefix[mid]%100;
        ans=min(ans,rec(l,mid)+rec(mid+1,r)+left_sum*right_sum);
    }

   return dp[l][r]=ans; 

}
void solve(){
    cin>>n;
    memset(prefix,0,sizeof(prefix));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i]=arr[i];
        if(i) prefix[i]+=prefix[i-1];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
  

}
 signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}