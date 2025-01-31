// here we partition the array into exactly k subarray in which we have to find the sum of minimum of each subarray
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int arr[10001];
int dp[1001][101];
int rec(int i,int x){
  //pruning
  if(x<0) return 1e9;
  
  //base case
   if(i==-1){
    // means we have been traversed all the element of array
      if(x==0){
        // means we have been split my array into k subarray
        return 0;
      }else{
        // invalid 
        return 1e9;
      }
   }


  // cache check
  if(dp[i][x]!=-1){
    return dp[i][x];
  }

  // transition
  // by using mean seen we maintain the minimum value from i to j+1 index of array   after that we apply the dp on the ramining element from j to j>=-1 to partition of remaing x-1 split 

  int ans=1e9;
  int min_seen=arr[i];
  // min_seen  min(arr[j+1..to ...i] tak)
  for(int j=i-1;j>=-1;j--){
     ans=min(ans,rec(j,x-1)+min_seen);
     min_seen=min(min_seen,arr[j]);
  }

  // save and return
  return dp[i][x]=ans;

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
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
