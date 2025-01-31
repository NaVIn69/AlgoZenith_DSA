#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 1e18
int n,m,q;
int dis[505][505];
void solve(){
    cin>>n>>m>>q;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i!=j){
                dis[i][j]=inf;
            }else{
                dis[i][j]=0;
            }
        }
    }
   
        
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }
   
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"0"<<endl;
            continue;
        }else{
            if(dis[a][b]==1e18){
                cout<<"-1"<<endl;
            }else{
                cout<<dis[a][b]<<endl;
            }
            
        }
    }

    
}
signed main(){
    solve();
}