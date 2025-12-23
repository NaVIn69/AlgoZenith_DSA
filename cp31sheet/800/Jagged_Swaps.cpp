#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int a[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    if(a[0]!=1){
        cout<<"NO"<<endl;
        return ;
    }
    if(maxi!=n){
        cout<<"NO"<<endl;
        return ;
    }
    // here we do swaping the value
    int l=10;
    while(l--){
    for(int i=1;i<n;i++){
        if(i==n-1) continue;
        if(a[i]>a[i+1]&&a[i]>a[i-1]){
            swap(a[i],a[i+1]);
        }
       
    }
}
    bool check=true;
    
    
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            check=false;
            break;
        }
    }
    
    if(check){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}