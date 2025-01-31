#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int n;
int a[1000000];
int binpow(int a,int p,int mod){
if(p==0) return 1%mod;
if(p%2) return a*binpow(a,p-1,mod);
else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}
}
pair<int,int>pair_XOR_AND(){
    int sum_xor=0;
    int sum_and=0;

for(int i=0;i<50;i++){
     int cnt[2]; cnt[1]=cnt[0]=0;
      for(int j=0;j<n;j++){
        if((1<<i)&a[j]){
            cnt[1]++;
        }else{
            cnt[0]++;
        }

      }
      int numpair_xor=cnt[1]*cnt[0];
      int numpair_and=cnt[1]*(cnt[1]-1);
      sum_xor+=(1<<i)*(numpair_xor);
      sum_xor=sum_xor%mod;
      sum_and+=(1<<i)*(numpair_and);
      sum_and=sum_and%mod;

}
return {sum_xor,sum_and};

}
int xor_sub(){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^a[i];
    }
    ans=ans*(1<<(n-1));
    ans=ans%mod;
}
int and_sub(){
    int ans=0;
    for(int i=0;i<50;i++){
      int set_bit=0;
      for(int j=0;j<n;j++){
        if((1LL<<i)&a[j]){
            set_bit++;
        }
      }
      int subset=(1LL<<set_bit)-1;

      ans+=(1LL<<i)*subset;
      ans=ans%mod;
    }
}
void solve(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
pair<int,int>p=pair_XOR_AND();
int xorsub=xor_sub();
int andsub=and_sub();
cout<<p.first%mod<<" "<<xorsub%mod<<" "<<p.second%mod<<" "<<andsub%mod<<endl;



}
signed main(){
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}