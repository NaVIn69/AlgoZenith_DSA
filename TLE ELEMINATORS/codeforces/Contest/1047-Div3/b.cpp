#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int a,b;
    cin>>a>>b;
    if(b%2){
        if(a%2){
            cout<<(a*b+1)<<endl;
        }else{
            cout<<-1<<endl;
      }
    }else{
        if(a%2==0 || b%4==0){
            cout<<(a*(b/2)+2)<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}