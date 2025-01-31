#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define endl "\n"
using state=pair<int,int>;
state st,en;
int n,m;
string arr[1000];
int dis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m){
        return true;
    }
    return false;

}
void bfs01(state sc_node){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j]=1e9;
        }
    }

   deque<state>dq;
   dq.push_front(sc_node);
   dis[sc_node.first][sc_node.second]=0;
   while(!dq.empty()){
     state node=dq.front();
     dq.pop_front();
     // moving to all the 4 neighbours node
     for(int i=0;i<4;i++){
        int nx=node.first+dx[i];
        int ny=node.second+dy[i];
        if(is_valid(nx,ny)){
            if(arr[nx][ny]=='#'){ // cost is 1
                if(dis[nx][ny]>dis[node.first][node.second]+1){
                    dis[nx][ny]=dis[node.first][node.second]+1;
                    // cout<<"cost 1 "<<node.first<<" "<<node.second<<endl;
                    dq.push_back({nx,ny});
                }
                }else{  // cost is 0
                    if(dis[nx][ny]>dis[node.first][node.second]){
                        dis[nx][ny]=dis[node.first][node.second];
                        dq.push_front({nx,ny});
                    }
                }
            
        }
     }
   }
}
void solve(){
 cin>>n>>m;
 for(int i=0;i<n;i++){
    cin>>arr[i];
    for(int j=0;j<m;j++){
        if(arr[i][j]=='s'){
         st={i,j};
        }else if(arr[i][j]=='f'){
            en={i,j};
        }
    }
 }

//  for(int i=0;i<n;i++){

//     for(int j=0;j<m;j++){
//         // if(arr[i][j]=='s'){
//         //  st={i,j};
//         // }else if(arr[i][j]=='f'){
//         //     en={i,j};
//         // }
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
//  }
 // here we have taken the input
 bfs01(st);
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<dis[i][j]<<" ";
    }
    cout<<endl;
 }

}
signed main(){
    solve();
}