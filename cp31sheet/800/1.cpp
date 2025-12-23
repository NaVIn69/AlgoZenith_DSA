#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
    
    }
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
             flag=false;
             break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else if(k<=1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}