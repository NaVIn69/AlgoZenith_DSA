#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    bool check=false;
    int mini=1e9;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]=(k-arr[i]%k);
        if(arr[i]==k){
            check=true;
        }
        mini=min(arr[i],mini);
    }
    if(check){
        cout<<0<<endl;
        return ;
    }
    cout<<mini<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}