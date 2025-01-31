#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int weight[1000];
int val[1000];
int dp[1000][1000];
int rec(int level,int wleft){
    if(level==n){
        return 0;
    }
    if(dp[level][wleft]!=-1){
        return dp[level][wleft];
    }
    int ans=0;
    // take that element
    if(wleft>=weight[level]){
        ans=max(ans,rec(level+1,wleft-weight[level]));
    }
    // dont take
    ans=max(ans,rec(level+1,wleft));
   return dp[level][wleft]=ans;

}
vector<int>sol;
void generating_sol(int level,int wleft){
    if(level==n){
       return ;
    }else{
        int donttake=rec(level+1,wleft);
        int take=0;
        if(wleft>=weight[level]){
            take=rec(level+1,wleft-weight[level]);
        }
        if(donttake>take){
            generating_sol(level+1,wleft);
        }else{
            sol.push_back(weight[level]);
            generating_sol(level+1,wleft-weight[level]);
        }

    }

}
void solve(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<rec(0,w)<<endl;
    generating_sol()



}
signed main(){

}