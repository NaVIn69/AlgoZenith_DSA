#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
#define F first
#define S second
int n,m;
vector<vector<int>>grid;
vector<vector<int>>dist,vis;
//here it return the cost of neighbours cell
 int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

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
    dist.assign(n,vector<int>(m,1e9));
    vis.assign(n,vector<int>(m,0));
     deque<state>dq;
     dq.push_back(sc_node);
     dist[0][0]=0;
     while(!dq.empty()){
        state node=dq.front();
        int x=node.F;
        int y=node.S;
        dq.pop_front();
         if(vis[node.F][node.S])continue;
         vis[node.F][node.S]=1;
        for (int k = 0; k < 4; k++) {
			int i = dx[k] + x, j = dy[k] + y;
			int w = (k + 1 == grid[x][y]) ? 0 : 1;
			if (i >= 0 && i < n && j >= 0 && j < m && dist[i][j] > dist[x][y] + w) {
				dist[i][j] = dist[x][y] + w;
				if (w==1)dq.push_back({i, j});
				else dq.push_front({i, j});
			}
		}

         }

     }

	
   


void solve(){
    cin>>n>>m;
    grid.assign(n,vector<int>(m));

    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin>>grid[i][j];
            
         }
    }

  bfs01({0,0});
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<dist[n-1][m-1]<<endl;

    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}