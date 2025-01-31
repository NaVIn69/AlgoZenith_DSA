#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int x[101],y[101];
int dp[101][101];
// for storing the which is my optimal answer for range (l....r) we use the back array
int back[101][101];
int rec(int l,int r){
    //purning
    if(l>r) return 0;
    // single matrix multiplication cost is 0
    if(l==r) return 0;
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=1e9;
    for(int mid=l;mid<r;mid++){
        // when we are using the back array we do some change in the transition
        // if current ans is less than the previous ans for range (l......r) then
        // update the answer
        if(rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r]<ans){
            ans=rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r];
            back[l][r]=mid;
        }
    }
    return dp[l][r]=ans;

}
// for ((1 2)3)
// here this will shows us the 
int opb[101];
int clb[101];
void generate(int l,int r){
  if(l==r){
    return ;
  }
  opb[l]++;
  clb[r]++;
  int mid=back[l][r];
  // here we  know the break point  between (l to r);
  generate(l,mid);
  generate(mid+1,r);

}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
    generate(0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<opb[i];j++){
            cout<<"(";
        }
        cout<<" "<<i<<" ";
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