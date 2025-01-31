#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,t;
int x[100100];
int rec(int level,int taken){
    // we have calculated the sum upto level 
    // purning
    if(taken>t) return 0;

    // basecase
    if(level==n){
        if(taken==t){
            return 1;
        }else{
            return 0;
        }
    }

    // cache check

    // transition
    // choice 
    //dont take
    int ans=rec(level+1,taken);

     //
    // svae and return
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    // target to find the subset
    cin>>t;
    cout<<rec(0,0);

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}