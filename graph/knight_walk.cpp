#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
using state=pair<int,int>;
vector<vector<int>>vis;
vector<vector<int>>dis;
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
bool is_valid(int x,int y,int n){
    if(x>=0&&x<n&&y>=0&&y<n){
        return 1;
    }
    return 0;
}
vector<state>neighbours(state node,int n){
       vector<state>neigh;
       for(int i=0;i<8;i++){
           int x=node.F+dx[i];
           int y=node.S+dy[i];
           if(is_valid(x,y,n)){
            neigh.push_back({x,y});
           }
       }
       
       return neigh;
}

void bfs(state st_node,int n){
    vis.assign(n+1,vector<int>(n,0));
    dis.assign(n+1,vector<int>(n,0));
    queue<state>q;
    vis[st_node.F][st_node.S]=1;
    dis[st_node.F][st_node.S]=0;
    q.push(st_node);
    while(!q.empty()){
        state node=q.front();
      //  cout<<node.F<<" "<<node.S<<endl;
        q.pop();
        for(state v:neighbours(node,n)){
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
    state st={Sx,Sy};
    state en={Fx,Fy};
  //  cout<<st.F<<" "<<st.S<<endl;
  if(Fx)
    bfs(st,N);
    if(!vis[en.F][en.S]){
        return -1;
    }else{
        return dis[en.F][en.S];
    }
}

signed main()
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

		 cout<<KnightWalk(N, Sx, Sy, Fx, Fy) <<endl;
	}
}