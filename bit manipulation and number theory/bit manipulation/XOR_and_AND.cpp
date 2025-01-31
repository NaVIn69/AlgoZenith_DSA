#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int binpow(int a,int p,int mod){
if(p==0) return 1%mod;
if(p%2) return a*binpow(a,p-1,mod);
else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}
}
int n;
int a[100100];
pair<int,int> sum_p_xor(){
    int sum_xor=0;
    int sum_and=0;
    for(int j=0;j<31;j++){
        int cnt[2]; cnt[1]=cnt[0]=0;

        for(int i=0;i<n;i++){
            if(a[i]&(1<<j)){
                cnt[1]++;
            }else{
                cnt[0]++;
            }
        }

        int numpairs_xor=cnt[0]*cnt[1];
        int numpairs_and=cnt[1]*(cnt[1]-1)/2;
        sum_xor+=numpairs_xor*(1LL<<j);
        sum_and+=numpairs_and*(1LL<<j);
        
    }
    pair<int,int>p;
    p.first=binpow(sum_xor,1,mod);
    p.second=binpow(sum_and,1,mod);
    return p;
}
int xor_sub(){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans|a[i];
    }
    ans=ans*(1LL<<(n-1));
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
    return ans;
}
void solve(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
pair<int,int>p=sum_p_xor();
pair<int,int>sub;
sub.first=and_sub();
sub.second=xor_sub();
cout<<((p.first%mod)+mod)%mod<<" "<<((sub.second%mod)+mod)%mod<<" "<<((p.second%mod)+mod)%mod<<" "<<((sub.first%mod)+mod)%mod<<endl;


}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}