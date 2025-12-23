#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,k;
int arr[100100];

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  sort(arr,arr+n);
  cin>>k;
  while(k--){
    int l,r;
    cin>>l>>r;
    int idx1=upper_bound(arr,arr+n,r)-arr;
    int idx2=lower_bound(arr,arr+n,l)-arr;
    cout<<idx1-idx2<<" ";
  }



}
signed main(){
    solve();
}