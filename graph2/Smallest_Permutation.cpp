#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>indeg,outdeg,topo;
void khan(){
   priority_queue<int>q;
   for(int i=1;i<=n;i++){
       if(indeg[i]==0) q.push(-i);
   }
   while(!q.empty()){
      int curr=-q.top();
      q.pop();
      topo.push_back(curr);
      for(auto v:g[curr]){
         indeg[v]--;
         if(indeg[v]==0) q.push(-v);
      }
   }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    outdeg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
       // outdeg[a++];
    }
    khan();
    if(topo.size()!=n){
        cout<<"-1"<<endl;
    }else{
        for(auto v:topo){
            cout<<v<<" ";
        }
        cout<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
