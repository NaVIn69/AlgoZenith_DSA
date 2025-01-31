#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x,k;
int skill[1001];
int taken[1001];
int tim[1001];
bool check(int level){
    int time_taken=0;
    int slot_taken=0;
    for(int i=0;i<level;i++){
        if(taken[i]){
            time_taken+=tim[i];
            slot_taken++;
        }
    }
    time_taken+=tim[level];
    slot_taken++;
    if(time_taken<=x&&slot_taken<=k){
        return 1;
    }
    return 0;
}
int rec(int level){
    // her this fn give me the maximum skill from level to n 
    // where we have taken some problem previous
    // purining
    if(x<0){
        // invalid case
        return -1e9;
    }

    if(level==n){
        // means we have gone through all the problem
        return 0;
    }
    // choice
    // dont take
    int ans=rec(level+1);

    // take
    // we can take that problem only that time when the time of that problem is less than x
    if(check(level)){
        taken[level]=1;
       
        ans=max(ans,skill[level]+rec(level+1));
         taken[level]=0;
    }
    return ans;


}
void solve(){
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>skill[i];
    }
    for(int i=0;i<n;i++){
        cin>>tim[i];
    }
    cout<<rec(0)<<endl;
     

}
signed main(){
    solve();
}