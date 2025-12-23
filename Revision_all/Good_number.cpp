#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k,q;
int prefix[1000100]; // one based indexing
void solve(){
    cin>>n>>k>>q;
    int maxi_r=0;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        maxi_r=max(maxi_r,r);
        prefix[l]+=1;
        prefix[r+1]-=1;
    }
    for(int i=1;i<=maxi_r+1;i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i=0;i<=maxi_r+1;i++){
        if(prefix[i]>=k){
          prefix[i]=1;
        }else{
            prefix[i]=0;
        }
    }
    for(int i=1;i<=maxi_r+1;i++){
        prefix[i]+=prefix[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}