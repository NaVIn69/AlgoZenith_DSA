/*
 here we have to divided the array into the k subarray such that sum of minimum of k subarray should be minimum
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[1001];
int dp[1001][101];
int rec(int i,int x){
     // purning
     if(x<0){
        return 1e9;
     }

     // base case
     if(i==-1){
        if(x==0){
            return 0;
        }else{
            // invalid case
            return 1e9;
        }
     }
       

     // cache check
     if(dp[i][x]!=-1){
        return dp[i][x];
     }

     // transition
     int ans=1e9;
     int min_seen=arr[i];
     for(int j=i-1;j>=-1;j--){
        ans=min(ans,rec(j,x-1)+min_seen);
        min_seen=min(min_seen,arr[j]);
     }
     
     // save and return
   return  dp[i][x]=ans;

}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,k)<<endl;


}
signed main(){
    solve();
}