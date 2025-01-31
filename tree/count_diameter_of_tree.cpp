#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[200200];
int dep[200200];
int par[200200];
int D;
int cnt;
// dfs function for the 
void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    if(dep[node]==(D/2-1))cnt++;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}
int cnt2=0;
// odd distance pe d/2 , 
void dfs2(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    if(dep[node]==(D/2))cnt2++;
    for(auto v:g[node]){
        if(v!=parent){
            dfs2(v,node,depth+1);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n==1){
        cout<<"1"<<endl;
        return;
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
    maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
    int second_point=maxch;
     int dia=dep[maxch];
     D=dia;
    //  cout<<D<<endl;
     if(dia%2){
        // odd size dia
        int curr=second_point;
        int len=dia/2;
        while(len--){
            curr=par[curr];
        }
        int first_center=curr;
        int second_center=par[curr];
        // cout<<first_center<<" "<<second_center<<endl;
        int ans1=0;
        int ans2=0;
        dfs2(first_center,second_center,0);
    
        ans1=cnt2;
        cnt2=0;
        dfs2(second_center,first_center,0);
        ans2=cnt2;
        cnt2=0;
        cout<<ans1*ans2<<endl;


     }else{
        // even size dia
        int curr=second_point;
        int len=dia/2;
        while(len--){
            curr=par[curr];
        }
          vector<int>ans;
        int center=curr;
       
        for(auto v:g[center]){
          
             dfs(v,center,0);
              ans.push_back(cnt);
              
              cnt=0;
        }
        int sum=ans.back();
        int ans2=0;
        for(int i=ans.size()-2;i>=0;i--){
             ans2+=(sum*ans[i]);
             sum+=ans[i];
        }
        cout<<ans2<<endl;

     }

   
}
signed main(){
    solve();
}