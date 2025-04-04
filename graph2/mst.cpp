#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct DSU{
 int n,setsize;
 vector<int>parent,size,rank;

 DSU(int a){
    n=a;
    setsize=n;
    parent.resize(n+1);
    size.assign(n+1,1);
    rank.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=i; // rank means the height of the tree
    }
 }

 int findUpar(int x){
   if(x==parent[x]) return x;
   return parent[x]=findUpar(parent[x]); // here we doing the pathe compression
}

void mergeBySize(int u,int v){
    int uroot=findUpar(u);
    int vroot=findUpar(v);
    if(uroot!=vroot){
      if(size[uroot]>size[vroot]){
         // then we connect the v root with u
         parent[v]=u;
         size[uroot]+=size[vroot];
      }else{
        parent[u]=v;
        size[vroot]+=size[uroot];
      }

    }
}

void mergeByRank(int x,int y){
   int xroot=findUpar(x);
        int yroot=findUpar(y);
        if(xroot!=yroot){
            if(rank[xroot]>rank[yroot]){
                 // x become the parent of y
                 parent[yroot]=xroot;

            }else if(rank[yroot]>rank[xroot]){
                parent[xroot]=yroot;
            }else{
                // here y become the parent 
                // and increasin the height of tree by 1
                parent[xroot]=yroot;
                rank[yroot]++;
            }
        }
}

void reset(){
    setsize=n;
     parent.resize(n+1);
    size.assign(n+1,1);
    rank.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=i; // rank means the height of the tree
    }
}


};
void solve(){
    int n,m;
    cin>>n>>m;
    DSU d(n);

    vector<pair<int,pair<int,int>>>edgelist;
    //{c,{a,b}} -> weight to a to b is c
    int cnt=0;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edgelist.push_back({c,{a,b}});
    }
    sort(edgelist.begin(),edgelist.end());
    // here from given graph we have to make a minimum spanning tree
    // for making maximum spanning tree we have to do like  we have to -c of the edge weight
    int mst_cost=0;
    int cnt=0; // counting the number of edge
    for(auto v:edgelist){
        int x=v.second.first;
        int y=v.second.second;
        if(d.findUpar(x)!=d.findUpar(y)){
            mst_cost+=v.first;
            cnt++;
            d.mergeByRank(x,y);
        }
    }
    if(cnt!=n-1){
        cout<<"No solution"<<endl;
        return ;
    }
    cout<<mst_cost<<endl;


}
signed main(){
    solve();
}