#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    int n,k;
    cin>>n>>k;
    // number of possible array which sum is maximum and and all the elements are 
    cout<<binpow(n,k,mod)<<endl;
    // if we have to find the maximum sum 
    // int l=0;
    // int tot=0;
    // int val=(1<<l);
    // int maxi=(1<<k)-1;
    // // cout<<maxi<<" "<<val<<endl;
    
    // for(int i=0;i<k;i++){
    //     tot+=(maxi-val);
    //     l++;
    //     val=(1<<l);
    // }
    // if(n<=k){
    // cout<<tot<<endl;
    // }else{
    //     int rem_ele_val=(n-k)*maxi;
    //     cout<<tot+rem_ele_val<<endl;
    // }
    // here we have been find the maximum sum of array

    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}