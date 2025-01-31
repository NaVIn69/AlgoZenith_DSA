#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli mod=1000000007;
void solve(){
lli n,q;
cin>>n>>q;
lli a[n];
for(int i=0;i<n;i++) cin>>a[i];
lli b[n];
// making prefix array
for(int i=0;i<n;i++){
    if(i==0){
        b[i]=a[i]%mod;
    }else{
        lli k=(a[i]%mod)+(b[i-1]%mod);
        b[i]=k%mod;
    }
}
while(q--){
    lli l,r;
    cin>>l>>r;
    l=l-1;
    r=r-1;
    if(l==r){
        cout<<((a[l]%mod)+mod)%mod<<endl;
    }else
    if(l==0){
        lli final=b[r];
        cout<<((final%mod)+mod)%mod<<endl;
    }else{
         lli final=b[r]-b[l-1];
        cout<<((final%mod)+mod)%mod<<endl;
    }


}



}
int main(){
    
    solve();
}
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
   int n,q;
    cin>>n>>q;
    int a[n+1]={0};
    for(int i=1;i<=n;i++){
     cin>>a[i];
    }
    int prefix[n+1]={0};
    for(int i=1;i<=n;i++){
     prefix[i]=a[i];
        if(i) prefix[i]+=prefix[i-1];
        if(prefix[i]<0){
      prefix[i]=prefix[i]+mod;
        }else{
      prefix[i]=prefix[i]%mod;
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=prefix[r]-prefix[l-1];
        cout<<(ans%mod+mod)%mod<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}