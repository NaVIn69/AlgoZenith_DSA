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
for(int i=0;i<n;i++) cin>>a[i];
/*int psi[n];
for(int i=0;i<n;i++){
    psi[i]=i-1;
    while(psi[i]!=-1 && a[i]<=a[psi[i]]){
        psi[i]=psi[psi[i]];
    }
    cout<<psi[i]+1<<" ";
}
cout<<endl;*/
stack<int>st;

for(int i=0;i<n;i++){
while(!st.empty()&&a[st.top()]>=a[i]){
 st.pop();
}
if(st.empty()){
    cout<<"0"<<" ";
}else{
    cout<<st.top()+1<<" ";
}
st.push(i);

}
    cout<<endl;




}
signed main(){
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}