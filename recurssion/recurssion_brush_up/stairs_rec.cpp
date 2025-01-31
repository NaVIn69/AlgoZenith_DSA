#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int rec(int level){
    // this fn tells me about the all the possible ways to reach from level...... n
    //purning
    if(level>n){
        return 0;
    }
    if(level==n){
        return 1;
    }
    // choices
    int ans=0;
    for(int step=1;step<=3;step++){
        // checking that can we go to the next step
        // here for that level we go through all the choice and add up to the ans for that level 
        if(level+step<=n){
         ans+=rec(level+step);
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    cout<<rec(1)<<endl;

}
signed main(){
    solve();
}