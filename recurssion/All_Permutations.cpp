#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  do{
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

  }while(next_permutation(a,a+n));
  
  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}