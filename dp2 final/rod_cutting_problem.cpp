#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int x[1001];
int dp[1001][1001];
// for generating the solution
int back[1001][1001];
int rec(int l,int r){
    if(l>=r) return 0;
   if(l+1==r){
    // we cant cut the single unit
    return 0;
   }
   if(dp[l][r]!=-1){
    return dp[l][r];
   }
   int ans=1e9;
   for(int p=l+1;p<=r-1;p++){
      if(x[r]-x[l]+rec(l,p)+rec(p,r)<ans){
        ans=x[r]-x[l]+rec(l,p)+rec(p,r);
        back[l][r]=p;
      }
   }
   return dp[l][r]=ans;
}
int opb[1001];
int clb[1001];
void generate(int l,int r){
   if(l>=r) return;
   if(l+1==r) return;
   opb[l]++;
   clb[r]++;
   int p=back[l][r];
   generate(l,p);
   generate(p,r);
}
void solve(){
cin>>n;
// these x[i] is cutting points on the rod
for(int i=0;i<n;i++){
    cin>>x[i];
}
memset(dp,-1,sizeof(dp));
cout<<rec(0,n-1)<<endl;
generate(0,n-1);
for(int i=0;i<n;i++){
    for(int j=0;j<opb[i];j++){
        cout<<"(";
    }
    cout<<" "<<x[i]<<" ";
    for(int j=0;j<clb[i];j++){
        cout<<")";
    }

}

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}