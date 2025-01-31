#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
 int a,b;
 cin>>a>>b;
 if(a==b){
    cout<<"0"<<endl;
    return;
 }
//  // here first we are doing the l^r after that prefix of both l and r is not going to change 
//  // we find the most significante bit of l^r
 int msb=a^b;
 int msb_idx=63-(__builtin_clzll(msb))+1;
//  // after that we have to set a with 1 1 ..
//  // after that msb_idx we have to set 0...
//  int ans=0;

//  for(int i=msb_idx;i>=0;i--){
//      a|=(1<<i);
//  }
//  for(int i=msb_idx;i>=0;i--){
//     b=(b&(~(1<<i)));
//  }
//  cout<<(a^b)<<endl;
cout<<((1LL<<msb_idx)-1)<<endl;



}
signed main(){
    solve();
}