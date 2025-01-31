#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
vector<int>sol;
vector<vector<int>>all_sol;
bool is_palindrome(vector<int>v){
    vector<int>v1(v.begin(),v.end());
    reverse(v1.begin(),v1.end());
    return v1==v;
}
void rec(int level){
    if(level==n){
        return;
    }
    //take
    sol.push_back(arr[level]);
    
    all_sol.push_back(sol);
    rec(level+1);
    sol.pop_back();
    //dont take;
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