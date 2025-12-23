#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
int mod=1e9+7;
int binpow(int a,int b){
    int ans=1;
    while(b){
        if(b%2){
            ans=(ans%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod);
        b=b>>1;
    }
    return ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // here we are using the contribution technique of the 
    // for subset each element appear 2^(n-1) times
    int ans_xor_pair=0;
    int ans_and_pair=0;
    for(int i=31;i>=0;;i--){
        int cnt[2]={0};
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1){
                cnt[1]++;
            }else{
                cnt[0]++;
            }
        }
        // here we have the 0 and 1 
        // we can add the contribution of ith bit 
        cnt[0]=cnt[0]%mod;
        cnt[1]=cnt[1]%mod;
        int cnt_xor=((cnt[0]%mod)*(cnt[1]%mod))%mod;
        int cnt_and=((cnt[1])*(cnt[1]-1)/2)%mod;
        ans_xor_pair+=((1LL<<i)*(cnt_xor));
        ans_and_pair+=((1LL<<i)*cnt_and)%mod;
        
    }
    int ans_xor_subset=0;
    int ans_and_subset=0;
    int val_2=binpow(2,n-1,mod);
    for(int i=0;i<n;i++){
        // contribution of ith elemet
        if(val2%2){
            ans_xor_subset+=
        }
    }

    

}
signed main(){
    solve();
}