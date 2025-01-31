#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> g[200200];
int dep[200200];
int par[200200];
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
    //here finding the first dia point
    int maxch=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[maxch]){
            maxch=i;
        }
    }
    //here maxch =i is the first dia point
    int first_dia_point=maxch;
    //cout<<first_dia_point<<endl;
    dfs(maxch,0,0);

    //by traversing the node finding the next dia point
     maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
    int second_dia_point=maxch;
    //cout<<second_dia_point<<endl;
    int dia=dep[maxch];
    //cout<<dia<<endl;
    if(dia%2){
        cout<<"-1"<<endl;
        return;
    }

    // if dia is odd then it is 2 centred 
    // if dia is even then it is 1 centred
    int len=dia/2;
    int curr=second_dia_point;
    while(len--){
        curr=par[curr];
    }
    cout<<curr<<endl;
    




}
signed main(){
    solve();
}