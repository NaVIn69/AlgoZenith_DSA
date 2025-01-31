#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
   int n;
   cin>>n;
   int arr[n];
   int cnt[60]={0};
   // here for every element we have to count how many set bit is present at the ith bit
   for(int i=0;i<n;i++){
    cin>>arr[i];
      for(int b=0;b<60;b++){
         if((arr[i]>>b)&1){
            cnt[b]++;
         }
      }
   }
   int ans=0;
  
   for(int j=0;j<n;j++){
    int c=arr[j];
     int and_val=0;
   int or_val=0;
     for(int i=0;i<60;i++){
        int val=(1LL<<i)%mod;
        if((c>>i)&1LL){
            and_val=(and_val+val*cnt[i])%mod;
            //here if c ke ith bit is set then
            // or for every element is 1
            or_val=(or_val+val*n)%mod; 
        }else{
            // c ke ith bit is 0 the cnt[i] ke sath only one hoga
            or_val=(or_val+val*cnt[i])%mod;

        }
     }
     ans=(ans+(and_val*or_val))%mod;
   }
   
   cout<<(ans%mod+mod)%mod<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}