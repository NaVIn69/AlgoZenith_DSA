#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
int n;
cin>>n;
int arr[n];
int cnt[21]={0};
for(int i=0;i<n;i++){
    cin>>arr[i];
    for(int j=0;j<=20;j++){
        if(arr[i]&(1<<j)){
            cnt[j]++;
        }
    }
}
// we have to traverse to the each bit and count number of 1 
// set the 1 to which has zero 
for(int i=0;i<n;i++){
    int largepos=0;
    for(int j=0;j<=20;j++){
      if(cnt[j]){
        
      }
    }
}

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