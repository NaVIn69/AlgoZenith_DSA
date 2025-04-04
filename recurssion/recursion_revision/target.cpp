#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,target;
int arr[1001];
vector<int>shared;
// this is shared across the recurssion ,this is also the part of the state
// print all the the element whoes sum is equal to the target
int  rec(int level,int rem){
    // we are on that level , 
    // that fn give me total number of ways to make rem sum from level to n-1
    if(level==n){
        if(rem==0){
            // here we get one of the solution from which i can get the rem sum from the level
            for(int i=0;i<shared.size();i++){
                cout<<shared[i]<<" ";
            }
            cout<<endl;
        return 1;
        }
        return 0;
    }
    // choice 
    // dont take /take the element of that level 
    // int ans=rec(level+1,rem);
    int ans=0;
    // take
    // check
    if(rem>=arr[level]){
        // take
        //move
        shared.push_back(arr[level]);
        ans+=rec(level+1,rem-arr[level]);
        // here by taking arr[level] element , we find the number of solution , then we pop_back() that element from
        // shared vector 
        // unplace  measn when we are doing backtrack , uss level se wapas jaa rhe hai , then we have to remove that element
        shared.pop_back();

    }
    ans+=rec(level+1,rem);
    return ans;
}
void solve(){
  cin>>n>>target;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
 cout<<rec(0,target)<<endl;


}
signed main(){
    solve();
}