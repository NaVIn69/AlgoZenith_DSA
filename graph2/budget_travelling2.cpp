#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
using state=pair<int,int>;
int dis[10100][105];
int vis[10100][105];
int n,m,k;
// k is the capacity of that car
vector<vector<pair<int,pair<int,int>>>>g;
int c[10100];
// a->{b,{p,d}};
// here my built graph store {dist,{node_number,remaing_petrol}}
void dijkstra(state st){
    // here we travelling all the node and on each node ma
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dis[i][j]=1e9;
            vis[i][j]=0;
        }
    }
    priority_queue<pair<int,state>>pq;
    // here int tell me about the distance of that node from the sources node and state tell me about on which node i am at and what is the remaing petrol in my car

    // from we pq we pop the edge with minimum distance 
    pq.push({0,st});
    dis[st.first][st.second]=0;
    while(!pq.empty()){
        auto val=pq.top();
        pq.pop();
        int cur_dis=-val.first;
        state cur_state=val.second;
        /// here cur_state.first is the node_number ,on which node number i am at the
        // cur_state.second tell me about the remaining petrol inside the car
        if(vis[cur_state.first][cur_state.second])continue;
         vis[cur_state.first][cur_state.second]=1;
         // here we travese all the edge of that node and puch into the priority queue
         for(auto v:g[cur_state.first]){
           if(cur_state.second>=v.second.first){
            // gaddi me petrol jyda hone chahiye then
             if(!vis[v.first][cur_state.second-v.second.first]&&dis[v.first][cur_state.second-v.second.first]>cur_dis){
                // relax the edge of my graph
                dis[v.first][cur_state.second-v.second.first]=cur_dis;
                // here push the node {with distance and node_number ,remaining petrol}
                pq.push({-cur_dis,{v.first,cur_state.second-v.second.first}});
             }
           }

         }
         // we can refill on that node 
         if(!vis[cur_state.first][cur_state.second+1]&&dis[cur_state.first][cur_state.second+1]>cur_dis+c[cur_state.first]){
             dis[cur_state.first][cur_state.second+1]=cur_dis+c[cur_state.first];
             pq.push({-dis[cur_state.first][cur_state.second+1],{cur_state.first,cur_state.second+1}});  
         }
    }
    
}

void solve(){
    cin>>n>>m;
  g.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b,d;
    cin>>a>>b>>d;
    // one unit of distance, you need one liter of petrol.
    g[a].push_back({b,{d,d}});
    g[b].push_back({a,{d,d}});
  }
  // here a->starting city
  // b->destination city
  //here cost of refill the petrol on that node
  for(int i=1;i<=n;i++){
    cin>>c[i];
  }
  int sc_node,en_node;
  cin>>sc_node>>en_node>>k;
  state st={sc_node,0};
  dijkstra(st);
  cout<<dis[en_node][0]<<endl;




}
signed main(){
    solve();
}