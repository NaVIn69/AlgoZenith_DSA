#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,x;
    cin>>n>>x;
    int mini_idx=1e9;
    int max_idx=0;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            mini_idx=min(mini_idx,i);
            max_idx=max(max_idx,i);
        }
    }
    int t=max_idx-mini_idx+1;
    if(x>=t){
        cout<<"YES"<<endl;
        return;
    }else{
        cout<<"NO"<<endl;
    }



}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}