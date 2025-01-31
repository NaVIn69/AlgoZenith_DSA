#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool  used[n+1];
    for(int i=0;i<n+1;i++){
        used[i]=false;
    }
    for(int i=0;i<n;i++){
        if(arr[i]<=n){
            used[arr[i]]=true;
        }
    }
    int res=0;
    while(used[res]){
        res++;
    }
    for(int i=0;i<n+1;i++){
        used[i]=false;
    }
    cout<<res<<endl;

    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}