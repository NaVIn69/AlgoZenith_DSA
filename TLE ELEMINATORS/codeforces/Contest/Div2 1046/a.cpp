#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
 int a,b,c,d;
 cin>>a>>b>>c>>d;
 int maxi=max(a,b);
 int mini=min(a,b);
 if(((maxi/2)-1)>=3){
    cout<<"NO"<<endl;
    return ;
 }
 maxi=max(c-a,d-a);
 mini=min(c-a,d-a);
 if(((maxi/2)-1)>=3){
    cout<<"NO"<<endl;
    return ;
 }
 cout<<"YES"<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}