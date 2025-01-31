#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int n,t;
int arr[1001];
vector<int>sol;
vector<vector<int>>all_sol;
int rec(int level,int left){
    // find the number of ways find the target sum by which we can select the multiple times same element
    if(left<0){
        return 0;
    }
    if(level==n){
    if(left==0){
        all_sol.push_back(sol);
        // here we have been find the one subsequence to whoes sum is target
        return 1;
    }
    return 0;
    }
    if(left==0){
        all_sol.push_back(sol);
        return 1;
    }
    // choice
    //take
    int ans=0;
    if(left>=arr[level]){
        sol.push_back(arr[level]);
       ans= rec(level,left-arr[level]);
       sol.pop_back();
    }
    // dont take
    ans=ans+rec(level+1,left);
    return ans;
}
void solve(){
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(0,t)<<endl;
    // here all_sol tells me about the 
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