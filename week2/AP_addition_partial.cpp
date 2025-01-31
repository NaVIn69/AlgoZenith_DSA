#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n+2,0);
    vector<int>b(n+2,0);

    while(q--){
        int a,d,l,r;
        cin>>a>>d>>l>>r;
        int k=(a-d*l);
         v[l]+=k;
         v[r+1]-=k;
         b[l]+=d;
         b[r+1]-=d;
    }
    /// making the prefix of both sum
    for(int i=1;i<=n;i++){
        v[i]=(v[i]%mod+v[i-1]%mod)%mod;
        b[i]=(b[i]%mod+b[i-1]%mod)%mod;
    }
    vector<int>arr;
    for(int i=1;i<=n;i++){
        int ans=(v[i]%mod+(b[i]%mod*i%mod)%mod)%mod;
      arr.push_back(ans);
    }
    for(int i=0;i<arr.size();i++){
        cout<<(arr[i]%mod+mod)%mod<<" ";
    }
    cout<<endl;


}
signed main(){
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
}