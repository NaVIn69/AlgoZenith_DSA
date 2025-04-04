#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;

vector<int>parent;
vector<pair<pair<int,int>,int>>edge;
vector<int>dis,dis2;
int x;
void bellman_ford(int sc_node){
    dis.assign(n+1,1e18);
    dis2.assign(n+1,0);
    parent.assign(n+1,-1);

    //traversing all the edge for n-1 times
    dis[sc_node]=0;
    for(int i=0;i<n-1;i++){
        for(auto e:edge){
            int a=e.first.first;
            int b=e.first.second;
            int w=e.second;
            // a ----> b
            //    w

            if(dis[b]>dis[a]+w){
                dis[b]=dis[a]+w;
                parent[b]=a;
                x=b;
            }
        }
    }
    for(int i=1;i<=n;i++){
        dis2[i]=dis[i];
    }
    for(int i=0;i<n-1;i++){
    for(auto e:edge){
        int a=e.first.first;
            int b=e.first.second;
            int w=e.second;
            // a ----> b
            //    w

            if(dis2[b]>dis2[a]+w){
                dis2[b]=dis2[a]+w;
            }
    }
    }
}
void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        //directed graph
        edge.push_back({{a,b},c});
    }
    // for finding the correct distance of every node from source node with +,-,0 weighted edge 
    //then we have to traverse the (n-1) time on every edge to find the correct distance
    int sc_node=1;
    cin>>sc_node;
    bellman_ford(sc_node);
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<dis[i]<<" : "<<dis2[i]<<endl;
    }

     for (int i = 1; i <=n; ++i)
            x = parent[x];

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    
    

    // dis[i] and dis2[i] differ at any node that tell me about that there is a -ve cycle


  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}