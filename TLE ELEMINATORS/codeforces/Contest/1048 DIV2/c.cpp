#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
   int a,b;
   cin>>a>>b;
   if(a==b){
    cout<<0<<endl;
    return ;
   }
   if(a%b==0){
     cout<<1<<endl;
   }else if(b%a==0){
      cout<<1<<endl;
   }else if(a==b){
      cout<<0<<endl;
   }else{
      cout<<2<<endl;
   }
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}