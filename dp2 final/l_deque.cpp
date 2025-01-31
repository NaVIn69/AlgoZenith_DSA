#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[3001];
int dp[3001][3001];
bool check=true;
// true pe taro chalega
// false pe jiro chalega
int rec(int l,int r){
    // this give me the maximum value obtained by the selecting either l or r;
  
}
void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 memset(dp,-1,sizeof(dp));
 cout<<rec(0,n-1)<<endl;

}
signed main(){
    solve();
}