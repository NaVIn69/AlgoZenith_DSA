// given array we have two player and we have to play a game 
// first player p1 ,p2
// M=(p1-p2) maximize 
// we can select element from both end (like deque) let assumme p1 has been start the game
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[1001];
int dp[1001][1001];
int done[1001][1001];
int rec(int l,int r){
    // dp(l,r) => if arr[l.....r] is left after some deletion of prefix and suffix what is the maximum M ,if player p1 plays first here

    //base case
    if(l==r){
        return arr[l];
    }

    //cache check
    if(done[l][r]){
        return dp[l][r];
    }

    //transition
    int ans=max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));
    done[l][r]=1;

    //save and return
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            done[i][j]=0;
        }
    }
   cout<<rec(0,n-1)<<endl;


}
signed main(){
    solve();
}