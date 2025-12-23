#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have given the array here we have to find the total number of k size subsequence
int n,k;
int arr[1001];

vector<int>sol;
// this is shared across all the recurssion
void rec(int level){
    
    if(level==n){
         if(sol.size()==k){
             for(auto x:sol){
                cout<<x<<" ";
             }
             cout<<endl;
         }
         return ;
    }

    // we have choice to take or dont take
    if(sol.size()<k){
        sol.push_back(arr[level]);
        // move to the  next level
        rec(level+1);
        // unplace
        sol.pop_back();
    }
    // dont take
    rec(level+1);
}
void solve(){
 cin>>n>>k;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 rec(0);
 

}
signed main(){
    solve(); 
}