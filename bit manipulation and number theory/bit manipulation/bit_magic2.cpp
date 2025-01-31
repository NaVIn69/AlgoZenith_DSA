#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
int n;
cin>>n;
int msb=-1;
int lsb=INT_MAX;
for(int i=63;i>=0;i--){
    if((n>>i)&1LL){
        cout<<"1";
        msb=max(msb,i);
        lsb=min(lsb,i);
    }else{
  cout<<"0";
    }
}
cout<<endl;
cout<<msb<<endl;


if(lsb==INT_MAX) cout<<"-1"<<endl;
 else cout<<lsb<<endl;


if(__builtin_popcountll(n)==1&&n!=1) cout<<"1"<<endl;
else cout<<"0"<<endl;

if(lsb==INT_MAX) cout<<"-1"<<endl;
 else cout<<(1LL<<lsb)<<endl;

if(n<=1) cout<<"2"<<endl;
else if(1LL<<msb==n) cout<<n<<endl;
else cout<<(1LL<<(msb+1))<<endl; 


}
signed main(){
 int t;
 cin>>t;
 while(t--){
    solve();
 }
}
