#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAX 200005
int n,q;
int arr[2*MAX];
int prefix[2*MAX];

void solve(){
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  while(q--){
      int l,r;
      cin>>l>>r;
      prefix[l]+=1;
      prefix[r+1]-=1;
  }
  for(int i=1;i<=n+1;i++){
     prefix[i]+=prefix[i-1];
  }
  sort(prefix,prefix+n+1);
  sort(arr+1,arr+n+1);
  
  int ans=0;
  for(int i=0;i<=n;i++){
    ans+=(prefix[i]*arr[i]);
  }
  cout<<ans<<endl;
}
signed main(){
     solve();
}