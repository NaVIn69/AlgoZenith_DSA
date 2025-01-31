#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
int n,m;
vector<vector<pair<int,int>>>g;
void solve(){
    cin>>n;
    g.resize(11);
    //ladder 
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,0});
    }
    //snake
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back({y,-1});
    }
    //we have to find the shortest path
    

   

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}