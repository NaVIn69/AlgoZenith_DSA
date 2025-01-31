
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
   int n,x;
   int a[100100];
   vector<vector<int>>all_sol;
   vector<int>sol;
   int sum=0;
void rec(int level){
    // base case
    if(level==n){
        // if(sum<=x){
        //     all_sol.push_back(sol);
        // }
        return;
    }
    // choice
    //take
    
        sol.push_back(a[level]);
        sum+=a[level];
        if(sum==x){
        all_sol.push_back(sol);
        }
        //move
        rec(level+1);
        //unplace 
        sum-=a[level];
        sol.pop_back();
    
    //dont take
    rec(level+1);

}
void solve(){
    
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    rec(0);
    for(int i=0;i<all_sol.size();i++){
        for(int j=0;j<all_sol[i].size();j++){
            cout<<all_sol[i][j]<<" ";
        }
        cout<<endl;
    }

}
signed main(){
    solve();
}