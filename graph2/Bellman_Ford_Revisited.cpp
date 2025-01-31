/*
You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<pair<pair<int,int>,int>>edge;
vector<int>dis,dis2,dis3;
bool check(int sc_node){
    //there is any cycle with with any +ve weight
     
}
int maxi(int sc_node){
   
}
void bellman_ford(int sc_node){
    dis.assign(n+1,1e18);

   // first trying to find the +ve cycle
   dis[sc_node]=0;
    for(int i=0;i<n-1;i++){
        for(auto e:edge){
            int a=e.first.first;
            int b=e.first.second;
            int w=e.second;
            if(dis[b]>dis[a]+w){
                dis[b]=dis[a]+w;
            }
        }
    }
    bool check=false;
    //  for(int i=0;i<n-1;i++){
        for(auto e:edge){
            int a=e.first.first;
            int b=e.first.second;
            int w=e.second;
            if(dis[b]>dis[a]+w){
                check=true;
                break;
            }
        }
    //}
    if(check){
        cout<<"-1"<<endl;
        return;
    }
    cout<<abs(dis[n])<<endl;

    
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        //directed graph
        edge.push_back({{a,b},-c});
    }
    bellman_ford(1);
    
    

  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}