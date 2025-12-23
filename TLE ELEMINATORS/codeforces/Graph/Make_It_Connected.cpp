#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct DSU{
    int n,setsize;
    vector<int>rank,size,parent;
   DSU(int sz){
     n=sz;
     setsize=sz;
     rank.resize(n+1);
     size.assign(n+1,1);
     parent.resize(n+1);
     for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=i;
     }
   }  

   int findUpar(int node){
       if(parent[node]==node){
          return node;
       }
       return parent[node]=findUpar(parent[node]);
   }

   void unionByRank(int a,int b){
        int Upar_a=findUpar(a);
        int Upar_b=findUpar(b);
        if(Upar_a==Upar_b)return ;
        if(rank[Upar_a]>rank[Upar_b]){
              parent[Upar_b]=Upar_a;
        }else if(rank[Upar_a]<rank[Upar_b]){
             parent[Upar_a]=Upar_b;
        }else{
            parent[Upar_a]=Upar_b;
            rank[Upar_b]++;
        }
   }

   void unionBySize(int a,int b){
    int Upar_a=findUpar(a);
    int Upar_b=findUpar(b);
    if(Upar_a==Upar_b)return ;
      if(size[Upar_a]<size[Upar_b]){
           parent[Upar_a]=Upar_b;
           size[Upar_b]+=size[Upar_a];
      }else{
         parent[Upar_b]=Upar_a;
         size[Upar_a]+=size[Upar_b];
      }
   }


};
int n,m;
vector<pair<int,pair<int,int>>>edgelist;
vector<int>vis;

void solve(){
  cin>>n>>m;
  edgelist.resize(n+1);
  vis.assign(n+1,0);
  vector<int>cost(n+1);
  int mn=1e18,mnpos=-1;
  for(int i=1;i<=n;i++){
     cin>>cost[i];
     if(cost[i]<mn){
        mn=cost[i];
        mnpos=i;
     }
  }
  // here we draw the fr edge from mnpos node to all the other node 

  for(int i=0;i<m;i++){
     int a,b,w;
     cin>>a>>b>>w;
     edgelist.push_back({w,{a,b}});
  }
    DSU d(n);
   for(int i=1;i<=n;i++){
        edgelist.push_back({mn+cost[i],{mnpos,i}});
   }
   sort(edgelist.begin(),edgelist.end());// here mst
   int ans=0;
   int cnt=0;
   for(int i=0;i<edgelist.size();i++){
         int wt=edgelist[i].first;
         int a=edgelist[i].second.first;
         int b=edgelist[i].second.second;
         int Upar_a=d.findUpar(a);
         int Upar_b=d.findUpar(b);
         if(Upar_a!=Upar_b){
             ans+=wt;
             d.unionByRank(a,b);
         }
   }
   cout<<ans<<endl;

}
signed main(){
    solve();
}