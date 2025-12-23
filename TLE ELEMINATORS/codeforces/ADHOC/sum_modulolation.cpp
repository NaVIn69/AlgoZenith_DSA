#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
  int n;
  cin>>n;
  int arr[n];
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  cout<<sum-n<<endl;
}
signed main(){
    solve();
}