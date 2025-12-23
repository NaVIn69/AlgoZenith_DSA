#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>dis;
vector<int>parent;
vector<int>numpath;
vector<int>col;

int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
void dfs(int sc_node,int par){
     vis[sc_node]=1;
     for(auto v:g[sc_node]){
         if(!vis[v]){
            dfs(v,sc_node);
         }else if(v!=par){
            // cycle is present 
         }
     }
}

void bfs(int sc_node){
    vis.assign(n+1,0);
    dis.assign(n+1,0);
    parent.assign(n+1,-1); // for printing the shortest path
    numpath.assign(n+1,0);
     dis[sc_node]=0;
     numpath[sc_node]=1;
     queue<int>q;
     q.push(sc_node);
     while(!q.empty()){
          int node=q.front();
          q.pop();
          if(vis[node])continue;
          vis[node]=1;
          for(auto v:g[node]){
                if(!vis[v]&&dis[v]>dis[node]+1){
                     dis[v]=dis[node]+1;
                     parent[v]=node;
                     numpath[v]=numpath[node];
                }else if(dis[v]==dis[node]+1){
                    numpath[v]+=numpath[node];
                }
          }
     } 
}

void bfs01(pair sc_node){
    vis.assign(n+1,0);
    dis.assign(n+1,1e9);
    deque<int>dq;
    dis[sc_node]=0;
    dq.push_back(sc_node);
    while(!dq.empty()){
        int node=dq.front();
        dq.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(auto v:g[node]){
             int neigh=v.first;
             int wt=v.second;
             if(dis[neigh]>dis[node]+wt){
                dis[neigh]=dis[node]+wt;
                if(wt==0){
                    dq.push_front(neigh);

                }else{
                    dq.push_back(neigh);
                }
             }
        }

    }
}

// here we have given the directed graph , here we have to find out the 
// first mark all the node color with 1 ,


bool is_cycle=false;
void dfs_color(int sc_node,int par){
     col[sc_node]=2;
     parent[sc_node]=par; 
     for(auto v:g[sc_node]){
            if(col[v]==1){
                dfs(v,sc_node);// forward edge
            }else if(col[v]==2){
                // backedge between sc_node->v , which is not going to traverseed
                if(!is_cycle){
                    is_cycle=true;
                    vector<int>path;
                    int temp=sc_node;
                    while(temp!=v){
                        path.push_back(temp);
                        temp=parent[temp];
                    }
                    path.push_back(v);
                    reverse(path.begin(),path.end());
                    for(auto v:path){
                        cout<<v<<" ";
                    }
                    cout<<endl;

                }
            }else{

            }
            col[v]=3;
     }
}

void cycle_directed(){
     col.assign(n+1,1);
     parent.assign(n+1,-1);
}

vector<int>indeg,outdeg,

void khan_algo(int sc_node){
    cin>>n>>m;
    indeg.assign(n+1,0);
    outdeg.assign(n+1,0);
    vector<int>topo;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
        outdeg[a]--;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
       for(auto v:g[node]){
           indeg[v]--;
           if(indeg[v]==0)q.push(v);
       } 
    }
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
}

void dijkstra(int sc_node){
    dis.assign(n+1,1e9);
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    numpath.assign(n+1,0);
    dis[sc_node]=0;
    numpath[sc_node]=1;
    priority_queue<pair<int,int>>pq;
    pq.push({-0,sc_node});
    while(!pq.empty()){
        pair<int,int>x=pq.top();
        int node=x.second;
        int wt=-x.first;// for this node wt is shortest distance
        pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
      for(auto v:g[node]){
          int neigh=v.first;
          int wt=v.second;
          if(!vis[neigh]&&dis[neigh]>dis[v]+wt){
             dis[neigh]=dis[v]+wt;
             parent[neigh]=node;
             numpath[neigh]=numpath[node];
             pq.push({-dis[neigh],neigh});           
           }else if(dis[neigh]==dis[v]+wt){
               numpath[neigh]+=numpath[node];
           }
      }

    }
}

vector<pair<int,int>,int>>edge;
vector<int>dis2;

// it gives me the shortest path between sources node to final node with edge -Ve, 0, +ve

void input_bellman(){
    cin>>n>>m;
edege.resize(n+1);
  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      edge.push_back({{a,b},c});
  }

}
void bellmanford(int sc_node){
   dis.assign(n+1,1e18);
   dis2.assign(n+1,0);
   parent.assign(n+1,-1);

   // every edge we have to relax n-1 times;

     for(int i=0;i<n-1;i++){
          for(auto v:g[sc_node]){
               int a=v.first.first;
               int b=v.first.second;
               int c=v.second;
               if(dis[b]>dis[a]+c){
                  dis[b]=dis[a]+c;
                  parent[b]=a;
               }
          }
     }
   
         
}
int distance[400][400];
int par[400][400];
// first make all pair distace with inf , after that take input of m edge with their weight
void floyd_warshall(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j) dis[i][j]=1e9;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }

    // here they are going from i->k->j
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    par[i][j]=par[k][j];
                }
                //  dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

}
void print_path(int sc_node){
    if(i!=j){
        print_path(i,par[i][j]);
    } 
    cout<<j<<endl;
}

vector<int> get_path(int src, int dest) {
    if (par[src][dest] == -1) return {};  // no path
    vector<int> path;
    int cur = dest;
    while (cur != src) {
        path.push_back(cur);
        cur = par[src][cur];
        if (cur == -1) return {}; // no path
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}


vector<pair<int,pair<int,int>>>edgelist;
struct DSU{
    int n,setsize;
    vector<int>parent,size,rank;
    DSU(int a){
        n=a;
        setsize=n;
        parent.resize(n+1);
        size.assign(n+1,1);
        rank.assign(n+1,0);
        for(int i=1;i<=n;i++){
             parent[i]=i;
             rank[i]=i;
        }
        
    }

    int findUpar(int a){
        if(a==parent[a]) return a;
        return parent[a]=find(parent[a]);
    }

    void mergeBySize(int a,int b){
        int Upar_a=findUpar(a);
        int Upar_b=findUpar(b);
        if(Upar_a==Upar_b) return ;
        if(size(Upar_a)>size(Upar_b)){
            parent[Upar_b]=Upar_a;
            size[Upar_a]+=size[Upar_b];
        }else{
            parent[Upar_a]=Upar_a;
            size[Upar_b]+=size[Upar_a];
        }
    }

    void mergeByRank(int a,int b){
        int Upar_a=findUpar(a);
        int Upar_b=findUpar(b);
        if(Upar_a==Upar_b) return ;
        if(rank[Upar_a]>rank[Upar_b]){
            parent[Upar_b]=Upar_a;
        }else if(rank[Upar_a]<rank[Upar_b]){
             parent[Upar_a]=Upar_b;
        }else{
            parent[Upar_a]=Upar_b;
            rank[Upar_b]++;
        }
    }

}

// krushkal 
void krushkal(){
    sort(edgelist.begin(),edgelist.end());
    // then 
     // here from given graph we have to make a minimum spanning tree
    // for making maximum spanning tree we have to do like  we have to -c of the edge weight
    int mst_cost=0;
    int cnt=0; // counting the number of edge
    for(auto v:edgelist){
        int x=v.second.first;
        int y=v.second.second;
        if(d.findUpar(x)!=d.findUpar(y)){
            mst_cost+=v.first;
            cnt++;
            d.mergeByRank(x,y);
        }
    }
    if(cnt!=n-1){
        cout<<"No solution"<<endl;
        return ;
    }
    cout<<mst_cost<<endl;
}

vector<vector<pair<int,int>>>g;
vector<int>vis;
void prims_algo(){
    // here we use the min heap and here find out the minimum cost 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0}); // wt node
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node])continue;
        vis[node]=1;
        sum+=wt;
        for(auto v:g[node]){
             if(!vis[v.first]){
                 pq.push({v.second,v.first});
             }
        }
    }


}




void solve(){
  cin>>n>>m;
  g.resize(n+1);
  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }
}
signed main(){
    solve();
}