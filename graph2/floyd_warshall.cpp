#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int dis[500][500];
int par[500][500];
void solve(){
    cin>>n>>m;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dis[i][j]=1e9;
        }
     }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=c;
    }
    //dis[i][j] tell me about the shortest path beteen i to j
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                   dis[i][j]=dis[i][k]+dis[k][j];
                   par[i][j]=par[k][j];
                }
            }
        }
    }

}
signed main(){
    solve();
}