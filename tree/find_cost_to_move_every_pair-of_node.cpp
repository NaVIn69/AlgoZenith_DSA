// if we are travesring all the pair node . then count what is the cost of traversing
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
vector<int>g[100100];
// here we have to count the contribution of evry edge
int par[100100];
int dep[100100];
int subtreesz[100100];
bool check[100100];
// this check array tells me about that node is traversed or not
void dfs(int node,int parent,int depth){
    par[node]=parent;
    dep[node]=depth;
    subtreesz[node]=1;
    for(auto v:g[node]){

        if(v!=parent){
            dfs(v,node,depth+1);
            subtreesz[node]+=subtreesz[v];
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // here  1 is the root of the tree
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        check[i]=false;
        
    }
    cout<<endl;
    int ans=0;
  for(int i=1;i<=n;i++){
    // here we have all the node 
    // every node we find all the 
    // i se connected sare edge pe treverse kr liya hu
    check[i]=true;
    
  
    for(auto v:g[i]){
      
           int sz1=subtreesz[i];
           int sz2=n-subtreesz[i];
           cout<<sz1<<" "<<sz2<<" "<<endl;
           ans+=(sz1*sz2);
       
    }
  }
  cout<<ans<<endl;


}
signed main(){
    solve();
}