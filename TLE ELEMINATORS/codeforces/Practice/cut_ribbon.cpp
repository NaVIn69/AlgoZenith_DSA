#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int rem=(n/m)*(m-1)+max(0,(n%m-1));
    // if(n==m&&k!=n){
    //   cout<<"YES"<<endl;
    //   return;
    // }
    if(k>=rem){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}