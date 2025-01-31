#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<string>ans;
string str="";
int n;
void rec(int open,int close){
   // base case
   if(open==close&&open+close==(2*n)){
     ans.push_back(str);
     return;
   }
   if(open<n){
    // choice
    //place
    str+='(';
    //recursive move
    rec(open+1,close);
    // unplace
    str.pop_back();
   }
   if(close<open){
    str+=')';
    rec(open,close+1);
    str.pop_back();
   }
}
void solve(){

    cin>>n;
    // here we have to generate all balanced paranthesis string
    rec(0,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}
signed main(){
    solve();
}