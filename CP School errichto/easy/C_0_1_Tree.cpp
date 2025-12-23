#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
vector<vector<pair<int,int>>>edge;

void dfs(int sc,vector<int>&vis,int edgeval,int comp_no){
    vis[sc]=comp_no;
      for(auto x:edge[sc]){
           int wt=x.second; // sc->node wt={0,1}
           int node=x.first;
           if(edgeval==wt&!vis[node]){
                
                dfs(node,vis,edgeval,comp_no);
           }

      }
}
void solve(){
  cin>>n;
  edge.resize(n+1);
  for(int i=0;i<n-1;i++){
      int a,b,c;
      cin>>a>>b>>c;
      edge[a].push_back({b,c});
      edge[b].push_back({a,c});
  }
     
  // here we have the edge a->b c {0,1}
  int size[n+1][2]={0};
    // find the component size 
  
    int ans=0;
  for(int j=0;j<=1;j++){    
    vector<int>vis(n+1,0);
    int comp_no=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp_no++;
            dfs(i,vis,j,comp_no);
        }
    }
    cout<<comp_no<<endl;

    vector<vector<int>>component(n+1);
    for(int i=1;i<=n;i++){
         component[vis[i]].push_back(i);
    }
      for(int i=1;i<=n;i++){
        int sz=component[i].size();
          if(sz!=0){
             ans+=(sz*(sz-1));
          }
      }
      // for all node we are storing the
    for(int k=1;k<=n;k++){
        size[k][j]=component[vis[k]].size();
    }
    
} 


   for(int i=1;i<=n;i++){
        ans+=(size[i][0]-1)*(size[i][1]-1);
   }
   cout<<ans<<endl;


}
signed main(){
    solve();
}