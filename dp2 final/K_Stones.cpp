#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[105];
int dp[100100];
int rec(int x){
  // this return can i win from this state by substracting the arr[i] from x
  if(x==0){
    return 0;
  }
  if(dp[x]!=-1){
    return dp[x];
  }
  int ans=0;
  for(int i=0;i<n;i++){
     if(arr[i]<=x){
        if(rec(x-arr[i])==0){
            ans=1;
            break;
        }
     }
  }
  return dp[x]=ans;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(k);
    if(ans==0){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
   

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}