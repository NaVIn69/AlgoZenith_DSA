#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int  n,k;
int arr[100100];
vector<vector<int>>all_sol;
vector<int>sol;
void rec(int level){
    if(level==n){
        return ;
    }

    // choice 
    // take
    if(sol.size()<k){
        sol.push_back(arr[level]);
        if(sol.size()==k){
        all_sol.push_back(sol);
        }
        rec(level+1);
        sol.pop_back();
    }
    //move recursively
    // rec(level+1);
    // // unplace
    // sol.pop_back();
    //dont take
    rec(level+1);
}

void solve(){
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
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