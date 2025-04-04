#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
struct UnionFind{
 int n,set_size,*parent,*rank;
 UnionFind(){}
 UnionFind(int a){
    n=set_size=a;
    // set_size tells me about the number of component
    parent=new int[n+1];
    rank=new int[n+1];
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=1;
        // rank is telling us the size of that subtree
    }
 }
 int find(int x){
    if(x==parent[x]){
        return x;
    }
    return find(parent[x]);
 }
 void merge(int x,int y){
    int xroot=find(x);
    int yroot=find(y);
    if(xroot!=yroot){
        // if they dont have the sameparent then we have 
        // here we have to see the rank of the both parent , then we have to merge
        if(rank[xroot]>=rank[yroot]){
            // here we merge the y with x means x becomes the parent of the y
            parent[yroot]=xroot;
            rank[xroot]+=rank[yroot];
        }else{
            // here we are mergin x with y means y becomes the parent of x
            parent[xroot]=yroot;
            rank[yroot]+=rank[xroot];
        }

    }
    set_size-=1;
 }
 void reset(){
    set_size=n;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=1;
    }
 }
 int size(){
    return set_size;
 }


};
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        // undirected graph
    }


}
signed main(){
    solve();
}