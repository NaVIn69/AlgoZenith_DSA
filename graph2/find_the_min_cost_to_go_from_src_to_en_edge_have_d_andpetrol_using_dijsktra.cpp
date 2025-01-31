/*
we have given a graph where each edge has a distance and petrol  between node .
//there is capacity of tank of car is k
each city has petrol tanki which cost is c[i];
/   1->we have to find the minimum cost to go from source to end node
2->  we have to find the shotest path  
*/
//  1 ka solution
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
#define F first
#define S second
#define mp make_pair
vector<vector<pair<int,state>>>g;
int c[1001];
//here c indicates the cost of each city where petrol is going to fill
int n,m,k;
int vis[1001][1001];
int dis[1001][1001];
//here dis[i][j] tells me about we  are at the ith node and j liter fuel is remaining in the car
void dijkstra(state st){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j]=1e9;
        }
    }
   dis[st.F][st.S]=0;
    priority_queue<pair<int,state>>pq;
    //here pq.top().first store the distance and 
    //2nd state tells me about the on which node is at that node and what is the petrol remaining 
    pq.push(make_pair(0,st));
    while(!pq.empty()){
        auto val=pq.top();
        pq.pop();
        int cur_dist=-val.F;
        state cur_state=val.S;
        //here cur_state tells me about on which node we are at and what is the petrol is remaining .
        //check visted
        if(vis[cur_state.F][cur_state.S]==1)continue;
        vis[cur_state.F][cur_state.S]=1;
        //here try all the neighbours
        //here graph me v.F node
        //here v.S.f petrol we need to go on that edge node->v
        //

        for(auto v:g[cur_state.F]){
            if(cur_state.S>=v.S.F){
                if(!vis[v.F][cur_state.S-v.S.F]&&dis[v.F][cur_state.S-v.S.F]>cur_dist+(0)){
                             dis[v.F][cur_state.S-v.S.F]=cur_dist+(0);
                             pq.push(make_pair(-dis[v.F][cur_state.S-v.S.F],make_pair(v.F,cur_state.S-v.S.F)));
                }

            }
        }
        if(cur_state.S<k){
            if(!vis[cur_state.F][cur_state.S+1]&&dis[cur_state.F][cur_state.S+1]>cur_dist+c[cur_state.F]){
                dis[cur_state.F][cur_state.S+1]=cur_dist+c[cur_state.F];
                pq.push(make_pair(-dis[cur_state.F][cur_state.S+1],make_pair(cur_state.F,cur_state.S+1)));
            }
        }

    }



}

void solve(){
    cin>>n>>m>>k;
    g.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=0;i<m;i++){
        int a,b,p,d;
        cin>>a>>b>>p>>d;
        g[a].push_back({b,{p,d}});
        g[b].push_back({a,{p,d}});
    }
    int st_node=1;
    int en_node=n;
    state st=make_pair(st_node,0);
    //we are starting with 1 node with zero fule
    dijkstra(st);
    cout<<dis[en_node][0]<<endl;


}
signed main(){
    solve();
}
