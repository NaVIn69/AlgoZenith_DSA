#include<bits/stdc++.h>
using namespace std;
#define int long long
#define end "\n"
int n,m;
int arr[1001][1001];
int dp[1001][1001];
// by the help of done array we computed that state is calculated or not 
int done[1001][1001];
int rec(int i,int j){
    // purning
    if(i<0||j<0){
        return -1e9;
    }
    // base case
    if(i==0&&j==0){
        return arr[0][0];
    }
    // cache check
    if(done[i][j]){
        return dp[i][j];
    }
    // transition
    int ans=-1e9;
    if(i!=0){
        ans=max(ans,rec(i-1,j)+arr[i][j]);
    }
    if(j!=0){
       ans=max(ans,rec(i,j-1)+arr[i][j]);
    }

    // save and return
    done[i][j]=1;
    return dp[i][j]=ans;
    
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            done[i][j]=0;
        }
    }
   cout<<rec(n-1,m-1)<<endl;


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}