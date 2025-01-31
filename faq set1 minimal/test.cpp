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
  sort(arr,arr+n);
  int a=0;
  int b=0;
  for(int i=0;i<n;i++){
       if(arr[i]!=i+1){
         a=arr[i];
         b=i+1;
         break;
       }
  }
  cout<<a<<" "<<b<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
