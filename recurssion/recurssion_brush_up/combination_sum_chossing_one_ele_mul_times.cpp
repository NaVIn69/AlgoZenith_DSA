#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,t;
int arr[1001];
vector<vector<int>>all_sol;
vector<int>sol;

// this solution vector is shared among the recursion code

// here we can select one element at one time
void rec(int level,int target){
    // before that level we have form some state() means we have form some sum 
    // this recursive function given all the possible sol to form the remaining sum from given previous state
    if(level==n){
        // means we have traverse all the element
        if(target==0){
            // means we have find the sol which sum is equal to target
         all_sol.push_back(sol);

        }
        return ;
    }

    // choice on that level
    // take
    // check   // can i take arr[level] element or not
    if(arr[level]<=target){
        sol.push_back(arr[level]);
        rec(level,target-arr[level]);
        sol.pop_back();
    }

    // dont take
    // here we not taking the arr[level] element
    rec(level+1,target);
}

void solve(){
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rec(0,t);
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