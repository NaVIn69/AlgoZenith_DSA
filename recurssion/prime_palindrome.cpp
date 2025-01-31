#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>v={1,2,3,4,5,6,7,8,9};
map<int,int>mpp;
int n=9;
 int digit;
// here we are generate all subset of size 3
vector<int>sol;
bool is_palindrome(vector<int>b){
    vector<int>v1(b.begin(),b.end());
    reverse(v1.begin(),v1.end());
    return v1==b;
}
  void rec(int level){
     if(level==n){
          if(sol.size()==digit){
            if(is_palindrome(sol)){
             for(auto v:sol) cout<<v<<" ";
             cout<<endl;
            }
            
          }
          return;
     }
     // choice
     //take
     if(sol.size()<digit){
        sol.push_back(v[level]);
        rec(level+1);
        sol.pop_back();
     }
     // dont take
     rec(level+1);

  }
void solve(){
 

  cin>>digit;
  //int digit=3;
  for(int i=0;i<9;i++){
     mpp[v[i]]=digit;
  }
  rec(0);
}
signed main(){
    solve();
}