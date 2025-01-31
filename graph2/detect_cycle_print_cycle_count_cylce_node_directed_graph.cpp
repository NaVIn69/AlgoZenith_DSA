#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
bool is_cycle=false;
vector<vector<int>>g;
// here we store the directed graph
vector<int>col;
// here it tell me about the node is visited or not 
// 
vector<int>parent;
vector<int>any_cycle;
//here any_cycle store the node of cycle
vector<int>cntcycle;
// here cntcycle store the which node is in how many cycle
vector<int>prefixorder;
// for counting the nodes in cycle we do the partial on node and v and also do the prefix sum in prefix order

 void dfs(int node,int par){
    parent[node]=par;
    col[node]=2;
    for(auto v:g[node]){
        // for undirected graph
        if(v==parent[node]) continue;
        if(col[v]==1){
            // node--v ke bich forward edge 
            // means we have to visit that node with dfs
            dfs(v,node);
        }else if(col[v]==2){
            // node -- v ke bich back edge 
            //here we have been detect the cycle
           // cout<<"hit:"<<" "<<node<<endl;
            if(is_cycle==0){
            int curr=node;
            while(curr!=v){
                any_cycle.push_back(curr);
                curr=parent[curr];
            }
            any_cycle.push_back(curr);
            reverse(any_cycle.begin(),any_cycle.end());
            }
            cntcycle[node]++;
            cntcycle[parent[v]]--;
            is_cycle=true;
        }else if(col[v]==3){
            // node v ke bich cross edge hai
        }
    }
    col[node]=3;
    //for doning the prefix sum we maintain the prefix order of that node
    prefixorder.push_back(node);
 }
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    parent.assign(n+1,0);
    cntcycle.assign(n+1,0);
    col.assign(n+1,1);
    map<pair<int,int>,int>edgecnt;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        // for undirected
       // g[b].push_back(a);
        // if(a==b){
        //     //self loop
        // }
        // if(a>b) swap(a,b);
        // edgecnt[make_pair(a,b)]++;
        // if(edgecnt[make_pair(a,b)]>1){
        //     //multiple edge
        // }else{
        //   g[a].push_back(b);
        //    g[b].push_back(a);
        // }
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);
        }
    }
   
    // for(auto v:any_cycle){
    //     cout<<v<<" ";
    // }
    // cout<<endl;
    for(auto v:prefixorder){
        cntcycle[parent[v]]+=cntcycle[v];
    }
    int cnt_node=0;
    for(int i=1;i<=n;i++){
        if(cntcycle[i]>0){
            cnt_node++;
        }
    }
    if(cnt_node>=2){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}
