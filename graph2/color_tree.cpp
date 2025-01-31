// here we have to find the how many color we need to make graph non-bipartite
#include<bits/stdc++.h>
using  namespace std;
#define int long long
#define endl "\n"
int n;
vector<vector<int>>g;
vector<int>vis;

void solve(){
  cin>>n;
  g.resize(n+1);
  vis.resize(n+1);
  for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
  }
  
}
signed main(){
    solve();
}