#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int l_r(vector<int>&prefix,int l,int r){
    if(l==0){
        return prefix[r];
    }
    return prefix[r]-prefix[l-1];
}

void solve(){
    int n,k;
    cin>>n>>k;
    char arr[n];
    vector<int>prefix(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]=='W'){
            prefix[i]=1;
        }
        if(i){
            prefix[i]+=prefix[i-1];
        }
    }
    int ans=1e9;
    for(int i=0;i<=n-k;i++){
     
            // cout<<i <<" "<<l_r(prefix,i,i+k-1)<<endl; // number of white from i to i+k 
        ans=min(ans,l_r(prefix,i,i+k-1));
        
    }
    if(ans==-1){
        cout<<k<<endl;
    }else{
        cout<<ans<<endl;
    }
    
    
    
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}