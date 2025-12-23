#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int a,b;
void solve(){
 cin>>a>>b;
 int ans=1;
 while(b){
    if(b%2==1){
        ans=(ans*a)%mod;
    }
    a=(a*a)%mod;
    b/=2;
 } 
 cout<<ans<<endl;

}
signed main(){
    solve();
}