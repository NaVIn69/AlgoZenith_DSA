#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,t;
int arr[1001];
vector<vector<int>>all_sub;
vector<int>shared;
void rec(int level,int target){
    // can we make target from level to n-1 by choosing the element from array

    if(level==n){
        if(target==0){
            for(auto x:shared){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return ;     
    }
    // here we have the choice 
    if(arr[level]<=target){
        shared.push_back(arr[level]);
        rec(level+1,target-arr[level]);// move to the next level
        shared.pop_back();
    }
    rec(level+1,target);
}
void solve(){
   cin>>n>>t;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   rec(0,t);
}
signed main(){
    solve();
}