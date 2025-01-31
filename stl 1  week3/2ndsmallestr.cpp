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
cin>>n;
int a[n];
set<int>s;
for(int i=0;i<n;i++){
    cin>>a[i];
    s.insert(a[i]);
}
if(s.size()==1){
cout<<"-1"<<endl;
}else{
auto it=s.begin();
it++;
cout<<*it<<'\n';
}
/*sort(a,a+n);
if(a[0]==a[n-1]||n==1){
    cout<<"-1";
    return ;
}
int ans=0;
for(int i=0;i<n;i++){
    if(i==n-1){
        continue;
    }
    if(a[i]!=a[i+1]){
        ans=a[i+1];
        break;
    }
}
cout<<ans<<'\n';*/

}
signed main(){
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}