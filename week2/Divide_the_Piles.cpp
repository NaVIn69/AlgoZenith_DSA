#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli gcd(lli a,lli b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
void solve(){
    lli n;
cin>>n;
lli a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
lli g=gcd(a[0],a[1]);
for(int i=2;i<n;i++){
    g=gcd(g,a[i]);
}

if(g>=2){
    cout<<"YES"<<'\n';
}else{
    cout<<"NO"<<'\n';
}

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}