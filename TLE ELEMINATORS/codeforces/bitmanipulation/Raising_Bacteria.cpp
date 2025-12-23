#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int x;
void solve(){
  cin>>x;
  int cnt=0;
  while(x){
    x=(x&(x-1));
    cnt++;
  }
  cout<<cnt<<endl;
}

signed main(){
    solve();
}