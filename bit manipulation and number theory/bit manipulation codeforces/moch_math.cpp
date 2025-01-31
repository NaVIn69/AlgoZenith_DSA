#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int ans=arr[0];
   for(int i=0;i<n;i++){
    ans=ans&arr[i];
   }
   cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}