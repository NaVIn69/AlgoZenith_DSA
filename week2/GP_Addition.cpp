#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;

int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return (a%mod *binpow(a,p-1,mod))%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}
void solve(){
    int n,k,q;
    cin>>n>>q>>k;
    vector<int>rpow(n+2,0);
    rpow[0]=1;
    int p=binpow(k,1,mod)%mod;
    for(int i=1;i<n+2;i++){
        rpow[i]=(p%mod*(rpow[i-1]%mod))%mod;
       
    }
    vector<int>v(n+2,0);
    for(int i=1;i<=q;i++){
        int a,l,r;
        cin>>a>>l>>r;
        v[l]=(v[l]%mod+a%mod)%mod;
        v[r+1]-=(a%mod*rpow[r-l+1]%mod)%mod;
    }
    
    // made the final array using prefix sum 
    for(int i=1;i<=n;i++){
        v[i]=(v[i]%mod+((v[i-1]%mod)*(k%mod))%mod)%mod;
    }
    for(int i=1;i<=n;i++){ 
        cout<<(v[i]%mod+mod)%mod<<" ";
    }
    cout<<endl;

}
signed main(){
    int t=1;
    while(t--){
        solve();
    }
}