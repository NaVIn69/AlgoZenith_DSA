#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state= pair<pair<int,int>,int>;
// here first store the {i,j} and second things store the weights 
// here we have to fid the minimum walls to break to reach from start to final point , cost of breaking the wall is 1 and cost of moving the empty cell si 0
int n,m;
vector<vector<char>>g;

// g tells me about 
vector<vector<pair<int,int>>>parent;
vector<vector<int>>dis;
// dis give me shortest distance from sources node to the final node
vector<vector<int>>vis;
// vis tells me about the that node is visited or not
vector<vector<int>>num_paths;
// it tells me about the number of path from sources node to the any ith node

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool is_valid(int x,int y){
     if(x>=0&&x<n&&y>=0&&y<m){
        return true;
     }
     return false;
}

vector<state>neighbours(pair<int,int> node){
    vector<state>neighs;
    for(int dir=0;dir<4;dir++){
       int nx=node.first+dx[dir];
       int ny=node.second+dy[dir];
       if(is_valid(nx,ny)){
           if(g[nx][ny]=='#'){
              neighs.push_back({{nx,ny},1});
           }else{
            neighs.push_back({{nx,ny},0});
           }
       }
       
    }
    return neighs;
}

void bfs01(pair<int,int> sc_node){
    dis.assign(n+1,vector<int>(m+1,1e9));
    vis.assign(n+1,vector<int>(m+1,0));
    parent.assign(n+1,vector<pair<int,int>>(m+1,{-1,-1}));
    deque<state>dq;
    dq.push_back({sc_node,0});
    dis[sc_node.first][sc_node.second]=0;
    while(!dq.empty()){
        pair<int,int> node=dq.front().first;
        dq.pop_front();
        if(vis[node.first][node.second]) continue;;
        vis[node.first][node.second]=1;
        for(auto v:neighbours(node)){ 
            pair<int,int>neigh=v.first;
            int weight=v.second;
            if(dis[neigh.first][neigh.second]>dis[node.first][node.second]+weight){
               dis[neigh.first][neigh.second]=dis[node.first][node.second]+weight;
            }
            if(weight==0){
                dq.push_front(v);
            }else{
                dq.push_back(v);
            }
        }
    }

}

void solve(){
    cin>>n>>m;
    g.resize((n+1),vector<char>(m+1));
    pair<int,int> st,fn;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='s'){
                st={i,j};
            }else if(g[i][j]=='f'){
                fn={i,j};
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
    cout<<dis[fn.first][fn.second]<<endl;



}
signed main(){
    solve();
}