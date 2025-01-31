#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
//i//nt arr[1000002]={0};
//int pre[1000002]={0};
void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    // here we are making to prefix array first a[i]*(i+1)  and second 
    int pre[n+1]={0};
    for(int i=1;i<=n;i++){
        pre[i]=((arr[i]*(i+1))%mod+pre[i-1]%mod)%mod;
        if(pre[i]<0){
            pre[i]+=mod;
        }
       // pre[i]=pre[i]%mod;
    }
    // 2nd prefix array
    int pre2[n+1]={0};
    for(int i=1;i<=n;i++){
        pre2[i]=arr[i];
        if(i) pre2[i]+=pre2[i-1];
        if(pre2[i]<0){
            pre2[i]+=mod;
        }
        pre2[i]=pre2[i]%mod;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans1=pre[r]-pre[l-1];
        int ans2=(pre2[r]-pre2[l-1])*l;
        int final=(ans1%mod-ans2%mod)%mod;
        cout<<(final%mod+mod)%mod<<endl;

    }



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
  ///  cin>>t;
    while(t--){
        solve();
    }
}
