
#include <bits/stdc++.h>
using namespace std;
using state=pair<int,int>;
#define F first
#define S second
using state=pair<int,int>;
vector<vector<int>>g;
vector<vector<int>>vis;
vector<vector<int>>dis;
int n;
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};
bool is_valid(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
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
void bfs(state sc_node,int n){
    vis.assign(n+1,vector<int>(n+1,0));
    dis.assign(n+1,vector<int>(n+1,0));
     queue<state>q;
     vis[sc_node.F][sc_node.S]=1;
     dis[sc_node.F][sc_node.S]=0;
     q.push(sc_node);
     while(!q.empty()){
        state node=q.front();
        q.pop();
        for(auto v:neighbours(node)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S]=1;
                dis[v.F][v.S]=dis[node.F][node.S]+1;
                q.push(v);
            }
        }
     }
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	// Complete the function
    n=N;
    g.assign(n+1,vector<int>(n+1,0));
    state st,en;
    st={Sx,Sy};
    en={Fx,Fy};
    if(Sx>Fx){
        state temp=st;
        st=en;
        en=temp;
    }else if(Sy>Fy){
        state temp=st;
        st=en;
        en=temp;
    }
    bfs(st,N);
    // distance vector tell me about that source node se final node tak janne ke liye kitna minimum_move lagega wo batt rha hai 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
  
    if(!vis[en.F][en.S]){
       return -1;
    }
        return dis[en.F][en.S];
    


}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
