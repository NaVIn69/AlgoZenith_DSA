#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int n;
int a[100100];
int binpow(int a,int p,int mod){
if(p==0) return 1%mod;
if(p%2) return a*binpow(a,p-1,mod);
else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}
}
void solve(){
int k;
cin>>n>>k;
int a[n];
priority_queue<int> pq;
for(int i=0;i<n;i++){
    cin>>a[i];
    pq.push(a[i]);
}
long long ans=0;
while(k--&&!pq.empty()){
    int k=pq.top();
    ans+=k;
    pq.push(k/2);
    pq.pop();
}
cout<<ans<<'\n';
}
signed main(){
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}