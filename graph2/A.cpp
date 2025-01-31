#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define state pair<int,int>
vector<int>parent;

int main()
{   
    int n;
int m;
   parent.assign(n+1,-1);
    cin>>n;
    unordered_map<int,int> mm;
    vector<vector<int>> edge[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mm[x]=i;
        
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,t;
        cin>>a>>b>>t;
        vector<int> v(2);
        v[0]=mm[b];
        v[1]=t;
        a=mm[a];
        edge[a].push_back(v);
    }
   
   int a,b;
   cin>>a>>b;
   a=mm[a];
   b=mm[b];
   
   vector<int> dist(n,1e9);
   vector<int> vis(n,0);
   priority_queue<pair<int,int>> pq;
   pq.push({0,a});
   dist[a]=0;
   while(!pq.empty()){
       state node = pq.top();
       pq.pop();
       int u = node.S;
       int d = -node.F;
       if(vis[u]) continue;
       vis[u]=1;
       for(auto e:edge[u]){
         int v = e[0];
         int wt = e[1];
         if(d+wt<dist[v]){
            parent[v]=u;
             dist[v]=d+wt;
             pq.push(MP(-dist[v],v));
         }
       }
   }
  
   cout<<dist[b]<<endl;
   vector<int>path;
   int temp=b;
   while(temp!=-1){
       path.push_back(temp);
       temp=parent[temp];
   }
   reverse(path.begin(),path.end());
   for(auto v:path){
    cout<<v<<
    
   }
   
   
   
}