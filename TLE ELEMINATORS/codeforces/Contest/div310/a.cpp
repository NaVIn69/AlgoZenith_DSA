#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
     int arr[n],brr[n];
     for(int i=0;i<n;i++){
      cin>>arr[i];
     }
     for(int j=0;j<n;j++){
      cin>>brr[j];
     }
     int ans=0;
     for(int i=0;i<n;i++){
      if(a[i]>b[i]){
        ans+=(a[i]-b[i]);
      }
      
     }
     cout<<ans<<endl;
    
    

  
    

}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}