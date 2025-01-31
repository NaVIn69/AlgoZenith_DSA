#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
using state = pair<int,int>;
// here we have to print the shortest path 

// n ->number of nodes  m->number of edges
// here nodes is the every cell of grid
/* 
6 6
s . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
e . . . . .
n= row
m=column
// frome start we can go up down front back

here we have to find the minimum step to reach the from S to F
*/
// for printing the path we store the parent of every node
vector<vector<state>>par;
int n,m;
// here we are takin vector<vector<int>>g represent that each node ke jo bhi usske neighbour hai i=usko us node ke vector me dal do
vector<vector<char>>g;
// here vis represent the visited array means it tells me about which nodes is traversed or not
vector<vector<int>>vis;
// dis vector tells me about the distance of ith node frome sources node
vector<vector<int>>dis;
// bfs -> means breadth first search means we search the element level wise
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n&&g[x][y]!='#'){
        return true;
    }
    return false;
}

// here we assume that we are at cell x ,y  we have to check which cell valid my neighbour
/*
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
*/
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
vector<state>neighbour(state node){
    vector<state>neigh;
     for(int i=0;i<8;i++){
        int x=node.F+dx[i];
        int y=node.S+dy[i];
        if(is_valid(x,y)){
             neigh.push_back({x,y});
        }
     }
    return neigh;
}
void bfs(state st_node){
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,0));
    par.assign(n,vector<state>(m,{-1,-1}));
    queue<state>q;
    vis[st_node.F][st_node.S]=1;
    dis[st_node.F][st_node.S]=0;
    par[st_node.F][st_node.S]={-1,-1};
    q.push(st_node);
    while(!q.empty()){
        state node=q.front();
        q.pop();
        for(auto v:neighbour(node)){
             if(!vis[v.F][v.S]){
                vis[v.F][v.S]=1;
                dis[v.F][v.S]=dis[node.F][node.S]+1;
                par[v.F][v.S]=node;
                q.push(v);
             }
        }

    }

}
void print_path(state en){
    vector<state>path;
    state curr=en;
    pair<int,int>check={-1,-1};
    while(curr!=check){
        path.push_back(curr);
        curr=par[curr.F][curr.S];
    }
    reverse(path.begin(),path.end());
    for(auto v:path){
        cout<<v.first<<" "<<v.second<<endl;
    }

}
void solve(){
    cin>>n>>m;
    state st,en;
    // here st means statring position
    // en= end position
    g.assign(n,vector<char>(m,0));
    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='s'){
                st={i,j};
            }else if(g[i][j]=='f'){
                en={i,j};
            }
          }
    }
    bfs(st);
    if(!vis[en.F][en.S]){
        cout<<"Not reachable";
    }else{
        cout<<dis[en.F][en.S]<<endl;
        print_path(en);
    }

     
   
    
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
