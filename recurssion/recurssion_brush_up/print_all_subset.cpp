#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int  n;
int arr[100100];
vector<vector<int>>all_sol;
vector<int>sol;
void rec(int level){
    if(level==n){
        return ;
    }

    // choice 
    // take
    sol.push_back(arr[level]);
    all_sol.push_back(sol);
    //move recursively
    rec(level+1);
    // unplace
    sol.pop_back();
    //dont take
    rec(level+1);
}

void solve(){
cin>>n;
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