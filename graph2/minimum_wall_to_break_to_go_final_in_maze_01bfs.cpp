#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define inf 1e9
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>dis;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
     vector<state>neigh;
     for(int i=0;i<4;i++){
        int x=node.F+dx[i];
        int y=node.S+dy[i];
        if(is_valid(x,y)){
            neigh.push_back({x,y});
        }
     }
     return neigh;


}
void bfs01(state sc_node){
    dis.assign(n,vector<int>(m,inf));
    dis[sc_node.F][sc_node.S]=0;
    deque<state>q;
    q.push_back(sc_node);
    while(!q.empty()){
        state node=q.front();
        q.pop_front();
        for(auto v:neighbours(node)){
            int edge_w=0;
            if(g[v.F][v.S]=='#') edge_w=1;
            if(dis[v.F][v.S]>dis[node.F][node.S]+edge_w){
                dis[v.F][v.S]=dis[node.F][node.S]+edge_w;
                if(edge_w==0){
                    q.push_front(v);
                }else{
                    q.push_back(v);
                }
            }


        }
    }

}
void solve(){
    cin>>n>>m;
    state st,en;
    g.assign(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='s'){
                st={i,j};
            }else if(g[i][j]=='e'){
                en={i,j};
            }
        }
    }
    bfs01(st);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dis[en.F][en.S]<<endl;


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}