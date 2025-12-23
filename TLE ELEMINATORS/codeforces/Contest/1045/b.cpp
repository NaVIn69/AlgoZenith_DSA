#include <bits/stdc++.h>
using namespace std;
#define int long long

int binpow(int a,int b,int p){
     int ans=1;
     while(b){
         if(b%2){
            ans=((ans%p)*(a%p))%p;

         }
         a=((a%p)*(a%p));
         b=b/2;
     }
     return ans;
}

void solve(){
      int n,k;
      cin>>n>>k;
      int arr[n];
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      vector<int> pr = {2,3,5,7,11,13,17,19,23,29};
      int p=-1;
      for(int i=0;i<pr.size();i++){
           if(pr[i]<=k+1&&k%pr[i]!=0){
              p=pr[i];
              break;
           }
      }
      int kinv=binpow((k%p),p-2,p);
      for(int i=0;i<n;i++){
        int rem=((arr[i] % p + p) % p);
        int need=(p - rem) % p;                  
        int mi=(1LL*need*kinv)%p;    
        int val=arr[i]+1LL*mi*k;    
        cout<<val<<" ";    
      }
      cout<<endl;
      
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}
