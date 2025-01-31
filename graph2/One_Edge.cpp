#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
void dfs(int node,int comp_num,int &cnt){
    if(!vis[node]) cnt++;
    vis[node]=comp_num;
    for(auto v:g[node]){
        if(!vis[v]){
         
            dfs(v,comp_num,cnt);
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
    vis.resize(n+1,0);
    int num_comp=0;
    vector<int>sz;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            num_comp++;
            int cnt=0;
        
            dfs(i,num_comp,cnt);
             sz.push_back(cnt);
        }
    }

    if(num_comp==1){
        cout<<"0"<<endl;
        return;
    }
    int ans=0;
    int sum=0;
    for(int i=0;i<sz.size();i++){
       sum+=sz[i];
       ans+=(sz[i]*sz[i]);
    }
    cout<<((sum*sum-ans)/2)<<endl;
  
    

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