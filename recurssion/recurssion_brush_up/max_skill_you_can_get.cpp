#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,x,k;
int skill[1001];
int t[1001];
int taken[1001];
bool check(int level){
    int time_taken=0;
    int slot=0;
    for(int i=0;i<level;i++){
        if(taken[i]){
            slot++;
            time_taken+=t[i];
        }
        // if(slot>=k||time_taken>=x) return 0;
    }
    slot++;
    time_taken+=t[level];
    if(time_taken<=x&&slot<=k) return 1;
    else return 0;
}
int rec(int level){
    // it given the max skill what i can get from here if previouslly i have taken some problem
    if(level==n){
        return 0;
    }



    // choice
    // dont take
  int  ans=rec(level+1);
    //take
    if(check(level)){
           //place
           taken[level]=1;
    ans=max(ans,skill[level]+rec(level+1));
      taken[level]=0;
    }
    //move recursive
   
    // unplace
    //revert
    

    return ans;
    
}
void solve(){
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
    cin>>skill[i];
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    cout<<rec(0)<<endl;





}
signed main(){
    solve();
}