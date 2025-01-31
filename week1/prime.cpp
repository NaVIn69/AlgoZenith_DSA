#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
    cin>>n;
    if(n==2){
cout<<"YES"<<endl;
        return;
    }
    if(n==1){
cout<<"NO"<<endl;
        return;
    }
    bool ans=true;
    for(int i=2;i<=n/2;i++){
     if(n%i==0){
ans=false;
         break;
     }
    }
    if(ans){
cout<<"YES"<<endl;
    }else{
cout<<"NO"<<endl;
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}