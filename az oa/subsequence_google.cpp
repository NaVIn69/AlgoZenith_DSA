#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
  int n,k;
  cin>>n>>k;
  int arr[n];
  int rem[n];
  map<int,int>mpp;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    rem[i]=arr[i]%k;
    mpp[rem[i]]++;
  }
    
  
}
signed main(){
    solve();
}