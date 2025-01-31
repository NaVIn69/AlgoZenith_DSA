#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ii=pair<int,int>;
using state=pair<int,int>;
int c[100100];
vector<vector<pair<int,ii>>>g;
int n,m,k;
int vis[1001][1001];
int dist[1001][1001];
// here distance array store for every cities what is the cost to for every liters of petrol
/*
 let assumen for node 1
 // these all are the node
 (1,0) -> at node 1 with o liter
 (1,1) -> at node 1 with 1 liter
 (1,2) -> at node 1 with 2 liter
 (1,.)
 .
 .
 .
 (1,k)
*/
void dijkstra(state st){
    // here n is the number of cities
    // here k is the capacity of that car tanki
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
              dist[i][j]=1e9;
              vis[i][j]=0;
        }
    }
    priority_queue<pair<int,state>>pq;
    // here priority queue store the node of my graph (which is formulated by me where node store the {distance ,{node_number, remaining petrol })
    dist[st.first][st.second]=0;
    pq.push({-0,st});
    // here 0 is the distance of that node from sources node and in the st we store upto that node what is the remaing petrol
    while(!pq.empty()){
        auto val=pq.top();
        pq.pop();
        int cur_dis=-val.first;
        state cur_state=val.second;
        // cur_dis store the distance upto that node
        // here cur_state.first store the node number
        // cur_state.second sttore the remaining petrol in the car
        // check visited
        if(vis[cur_state.first][cur_state.second]) continue;
        vis[cur_state.first][cur_state.second]=1;
        for(auto v:g[cur_state.first]){
            // here v denotes the node of original graph which store the a-> (b,{p,d})
            if(cur_state.second>=v.second.first){
                // we can move to the next node
                // with remaining petrol (curr_state.second-v.second.first)
                // relax that edge 
                if(!vis[v.first][cur_state.second-v.second.first] && dist[v.first][cur_state.second-v.second.first]>cur_dis){
                    // here we are relaxing the edge of my graph (made by me)
                    dist[v.first][cur_state.second-v.second.first]=cur_dis;
                    // after relaxing the edge we push into the priority_queue
                    pq.push({-cur_dis,{v.first,cur_state.second-v.second.first}});
                }
            }

        }
        // here we have to refill
        // we are on the same node we can refill our car if jo state refill kr rhe hai wo phale is visited nhi ho and uss state ko relax kr ske
        if(!vis[cur_state.first][cur_state.second+1]&&dist[cur_state.first][cur_state.second+1]>cur_dis+c[cur_state.first]){
            dist[cur_state.first][cur_state.second+1]=cur_dis+c[cur_state.first];
            pq.push({-dist[cur_state.first][cur_state.second+1],{cur_state.first,cur_state.second+1}});
        }
    }
}
void solve(){
 cin>>n>>m>>k;
 g.resize(n+1);
 int st_node=1;
 int en=n;
 for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    int p,d; cin>>d;
    g[a].push_back({b,{d,d}});
    g[b].push_back({a,{d,d}});
    // here a se b connected hai and {p,d} petrol and distance d between a and b

 }
 for(int i=1;i<=n;i++){
    cin>>c[i];
 }
  state st={st_node,0};
  dijkstra(st);
//   for(int i=1;i<=n;i++){
//     for(int j=0;j<=k;j++){
//         cout<<dist[i][j]<<" ";
//     }
//     cout<<endl;
//   }
  cout<<dist[en][0]<<endl;
 

}
signed main(){
  solve();
}