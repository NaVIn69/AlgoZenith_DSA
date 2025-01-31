#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++){
     a[i]=i+1;
  }
  //sort(a,a+n);
  int cnt=1;
  do{
    if(cnt==k){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    }
cnt++;

  }while(next_permutation(a,a+n));
  
  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}