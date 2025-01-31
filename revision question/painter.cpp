#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,k;
int arr[100100];
bool check(int mid){
    int needed_painter=1;
    int val=mid;
    for(int i=0;i<n;i++){
      if(val>=arr[i]){
        val-=arr[i];
      }else{
         val=mid;
         needed_painter++;
         if(val>=arr[i]){
            val-=arr[i];
         }else{
            return false;
         }
      }
      if(needed_painter>k) return false;

    }
    return needed_painter<=k;
}
void solve(){
  cin>>n>>k;
  int mini=0;
  int tot=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    mini=max(mini,arr[i]);
    tot+=arr[i];
  }
  int l=mini;
  int h=tot;
  int ans=0;
  while(l<=h){
    int mid=(l+h)/2;
    if(check(mid)){
       ans=mid;
       h=mid-1;
    }else{
        l=mid+1;
    }
  }
  cout<<ans<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}