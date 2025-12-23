#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[100100];
int dep[100100];
int par[100100];
int D;
int cnt;
// this dfs for the odd size dia 
void dfs(int node,int parent ,int depth){
    par[node]=parent;
    dep[node]=depth;
    if(dep[node]==(D/2))cnt++;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }

}
int cnt2=0;
// this dfs for the even size dia
void dfs2(int node,int parent,int depth){
      par[node]=parent;
     dep[node]=depth;
   if(dep[node]==(D/2-1)) cnt2++;
    for(auto v:g[node]){
        if(v!=parent){

            dfs2(v,node,depth+1);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    int maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
    int first_point=maxch;
    dfs(maxch,0,0);
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[maxch]){
            maxch=i;
        }
    }
    int second_point=maxch;
    int d=dep[maxch];
    D=d;
    cout<<"dia"<<" "<<d<<endl;
    
    // for findig the number of dia 
    if(d%2==0){
        // here we have even dia the
        // sigle center 
        // from that center we have to move to all the subtree  count the number of nodes at distance of(d/2-1);
        int center=0;
        int node=maxch;
        int temp=d/2;
         while(temp--){
            node=par[node];
         }
         cout<<"center"<<" "<<node<<endl;
         center=node;
         // here we find the center 
         // we have to travel to all the subtree of that parent node
         vector<int>all_node_cnt;
         for(auto v:g[node]){
            cout<<v<<" "<<endl;
            dfs2(v,center,0);
         
            all_node_cnt.push_back(cnt);
            cnt=0;

         }
      
         // here we have to do the all pair product
         int tot=0;
         int sum=all_node_cnt.back();
         for(int i=all_node_cnt.size()-2;i>=0;i--){
             tot+=(sum*all_node_cnt[i]);
             sum+=all_node_cnt[i];
         }
         cout<<tot<<endl;

    }else{
        // here we have to find the both center
        int c1=maxch;
        int c2=0;
        int temp=d/2;
        while(temp--){
            c1=par[c1];
        }
        // here this is the 2nd center
        c2=par[c1];
        //
        int ans1=0;
        dfs(c1,c2,0);
        ans1=cnt;
        dfs(c2,c1,0);
        int ans2=cnt;
        cout<<ans1*ans2<<endl;
        


    }

}
signed main(){
    solve();
}