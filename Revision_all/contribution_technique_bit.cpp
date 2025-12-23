#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int ans=0;
  for(int i=31;i>=0;i--){
        int cnt[2]={0};
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1){
                // ith bit of arr[j] is set
                cnt[1]++;
            }else{
                cnt[0]++;
            }
        }
        ans+=(cnt[0]*cnt[1];)

  }
}
signed main(){
    solve();
}