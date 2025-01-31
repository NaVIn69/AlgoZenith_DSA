#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[100100];
int dep[100100];
int par[100100];
int D;
int cnt=0;

void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    // this is the first traversing of finding the one end point of dia
    int maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
    // this is the first end point of the diameter
    
    dfs(maxch,0,0);
    maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
    // dfs(maxch,0,0);
    // cout<<"one end point"<<" "<<maxch<<endl;
    int d=dep[maxch];
    cout<<"dia"<<" "<<d<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<par[i]<<" ";
    // }
    // cout<<endl;
 
   
        // we have to traverse the d/2 distance
        // maxch is the end point of dia

        int node=maxch;
        int dist=d/2;
        while(dist--){
            node=par[node];
        }
        if(d%2==0){
        cout<<node<<endl;
        }else{
            // odd dia has the two center
            cout<<node<<endl;
            cout<<par[node]<<endl;
        }
   // here depth [maxch ] tells me aboout tha dep[]
   




}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}