#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;

int n,m;
vector<vector<pair<int,int>>>g;
vector<int>vis,dis,par;

int power(int x,int y){
  int res=1;
  while(y){
    if(y%2){
      res =((res%mod)*(x%mod))%mod;
    }
    x=((x%mod)*(x%mod))%mod;
    y=y/2;
  }
  return res%mod;
}
void sssp(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e19);
    par.assign(n+1,-1);
    priority_queue<pair<int,int>>q;
    q.push(make_pair(0,sc));
    dis[sc]=0;
    while(!q.empty()){
          int node=q.top().second;
          q.pop();
          if(vis[node]) continue;
          vis[node]=1;
          for(auto v:g[node]){
             int neigh=v.first;
             int w=v.second;
              if(dis[neigh]>dis[node]+w){
                dis[neigh]=(dis[node]%mod+w%mod)%mod;
                par[neigh]=node;
                q.push({-dis[neigh],neigh});
              }
          }
    }
}
vector<int> print_path(int t){
    vector<int>ans;
    int curr=t;
    while(curr!=-1){
        ans.push_back(curr);
        curr=par[curr];
    }
    //ans.push_back(1);
    reverse(ans.begin(),ans.end());
   return ans;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int val=power(2,c);
        g[a].push_back({b,val});
       g[b].push_back({a,val});
    }
    int s,t;
    cin>>s>>t;
    sssp(s);
  
    if(vis[t]!=0){
     vector<int>path=print_path(t);
     cout<<(dis[t]%mod+mod)%mod<<endl;
     cout<<path.size()<<endl;
     for(auto v:path){
        cout<<v<<" ";
     }
     cout<<endl;
     
    }else{
        cout<<"-1"<<endl;
    }
    


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}