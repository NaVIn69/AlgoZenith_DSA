#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// find the total number of ways to reach at the level n
int n;
int rec(int level){
    // total number of way to reach from level to n
    if(level==n){
        // if we reach at the n the , it is the one wway
        return 1;
    }
    int ans=0;
    for(int ch=1;ch<=3;ch++){
        if(level+ch<=n){
          ans+=rec(level+ch);
        }
    }
    return ans;
}
void solve(){
  cin>>n;
  cout<<rec(1)<<endl;
}
signed main(){
    solve();
}