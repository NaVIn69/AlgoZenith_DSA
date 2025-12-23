#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  if(n==1){
    cout<<arr[0]<<endl;
    return ;
  }
  // here we have a1, a2, a3, a4, a5 ,a6, a7, a8 -> here we have x in between then then minimal possible value of k+1 we can obtain at ai, ot ai+k
  int ans = 1e9, bestX = -1;
  for (int i = 0; i < n - k; i++) {
      int spread = arr[i + k] - arr[i];
      int radius = (spread + 1) / 2;           // minimal possible fk(x) in this window
      int candidate = (arr[i] + arr[i + k]) / 2; // middle point
  
      if (radius < ans) {
          ans = radius;
          bestX = candidate;
      }
  }
  cout << bestX << endl;
  

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}