#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
#define F first
#define S second
int n,m;
 state st,en;
vector<vector<char>>arr;
vector<vector<int>>vis;
vector<vector<int>>dis;
vector<vector<state>>par;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#'){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
           vector<state>neigh;
        for(int i=0;i<4;i++){
            int x=node.F+dx[i];
            int y=node.S+dy[i];
            if(valid(x,y)){
                neigh.push_back({x,y});
            }
        }
        return neigh;
}
void bfs(state sc_node){
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,1e9));
    par.assign(n,vector<state>(m,{-1,-1}));
    vis[sc_node.F][sc_node.S]=1;
    dis[sc_node.F][sc_node.S]=0;
    par[sc_node.F][sc_node.S]={0,0};
    queue<state>q;
    q.push(sc_node);
   while(!q.empty()){
        state node=q.front();
        q.pop();
        // if(vis[node.F][node.S])continue;
        // vis[node.F][node.S]=1;
        for(state v:neighbours(node)){
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
    while(curr!=st){
        path.push_back(curr);
        curr=par[curr.F][curr.S];
    }
    path.push_back(st);
    reverse(path.begin(),path.end());
    for(state v:path){
        cout<<v.F<<" "<<v.S<<endl;
    }

    
}
void solve(){
    cin>>n>>m;
   arr.assign(n,vector<char>(m,0));
    // state st,en;
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='s'){
                st={i,j};
            }
            if(arr[i][j]=='e'){
                en={i,j};
            }
         }
    }
    bfs(st);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dis[en.F][en.S]==1e9){
        cout<<"not reached"<<endl;
    }else{
        cout<<dis[en.F][en.S]<<endl;
        print_path(en);
    }



}
signed main(){
    solve();
}