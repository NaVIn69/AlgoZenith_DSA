#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
  int n;
  cin>>n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  // alice always increase the total sum array
  // when bob chance comes it take all array sum
  // here we have to find the minimum subarray sum;
  int ans=0;
  int sum=arr[0];
  int curr=arr[0];
   for(int i=1;i<n;i++){
    sum+=arr[i];
    ans=min(ans,curr+arr[i]);
    curr=min(curr+arr[i],arr[i]);

   }
   cout<<sum+abs(2*ans)<<endl;
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