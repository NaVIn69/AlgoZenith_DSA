#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// SORTING THE edgelist will solve all the things , here we have been  sorted the edgelist according to their weight and then reverse it with their weight
struct DSU{
  int n; // number of node
  int setsize; // connected component
  vector<int>parent,size,rank;
  DSU(int a){
    n=a;
    setsize=a;
    parent.resize(n+1);
    size.assign(n+1,1);
    rank.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        rank[i]=i;
    }
  }
  int findUpar(int x){
    if(x==parent[x])return x;
    return parent[x]=findUpar(parent[x]);
  }
  // here we are merging the nodes then we have count in how many path have that edge as minimum edge 
  // here rank of any node tells me about 
  void mergeBysize(int x,int y){
    int xroot=findUpar(x);
    int yroot=findUpar(y);
    if(xroot!=yroot){
        if(size[xroot]>=size[yroot]){
            // here x will become the parent of y
          parent[yroot]=xroot;
          size[xroot]+=size[yroot];
        }else{
            parent[xroot]=yroot;
            size[yroot]+=size[xroot];

        }
    }
  }


};
void solve(){
  int n;
  cin>>n;
  vector<pair<pair<int,pair<int,int>>,int>>edgelist;
  for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;
      a--,b--;
      int c=b-a;
      edgelist.push_back({{c,{a,b}},i+1});
  }

  DSU d(2*n);
  sort(edgelist.rbegin(),edgelist.rend());
  vector<int>ans;
  int min_cost=0;
  for(int i=0;i<n;i++){
    int a=edgelist[i].first.second.first;
    int b=edgelist[i].first.second.second;
    int oridx=edgelist[i].second;
   int ua=d.findUpar(a);
   int ub=d.findUpar(b);
   cout<<ua<<" "<<ub<<endl;
   // when we are mergin the two nodes , then their ultimate parent tells me the size of that subtree , bcz during mergin that node look like ultimate node
      if(ub!=ua){
        d.mergeBysize(a,b);
        ans.push_back(oridx);// one based 
      } 
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}