#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>dis_p,dis_m,vis_p,vis_m;
queue<pair<int,int>>monster,person;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!='#'){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
    vector<state>neigh;
    for(int i=0;i<4;i++){
        int x=node.first+dx[i];
        int y=node.second+dy[i];
        if(is_valid(x,y)){
            neigh.push_back({x,y});
        }
    }
    return neigh;
}
void bfs_p(){
    //vis_p.assign(n,vector<int>(m,0));
  
     while(!person.empty()){
        auto node=person.front();
        //vis_p[node.first][node.second]=1;
        person.pop();
        for(auto v:neighbours(node)){
             if(dis_p[v.first][v.second]==-1){
           //     vis_p[v.first][v.second]=1;
                dis_p[v.first][v.second]=dis_p[node.first][node.second]+1;
                person.push(v);
             }
        }
     }
     

}
void bfs_m(){
   // vis_m.assign(n,vector<int>(m,0));
   
     while(!monster.empty()){
        auto node=monster.front();
       // vis_m[node.first][node.second]=1;
        monster.pop();
        for(auto v:neighbours(node)){
              if(dis_m[v.first][v.second]==-1){
               // vis_m[v.first][v.second]=1;
                dis_m[v.first][v.second]=dis_m[node.first][node.second]+1;
                monster.push(v);
             }
        }
     }
    
}
void solve(){
cin>>n>>m;
g.assign(n,vector<char>(m));
dis_p.assign(n,vector<int>(m,-1));
dis_m.assign(n,vector<int>(m,-1));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>g[i][j];
        if(g[i][j]=='A'){
            person.push({i,j});
            dis_p[i][j]=0;
        }else if(g[i][j]=='M'){
            dis_m[i][j]=0;
            monster.push({i,j});
        }
    }
}
bool check_p=false;
bool check_m=false;
if(person.empty()){
    cout<<"NO"<<endl;
    return;
}
if(!monster.empty()){
   check_m=true;
}
bfs_p();
bfs_m();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<dis_p[i][j]<<" ";
    }
    cout<<endl;
  }
// bool check_p=false;
// bool check_m=false;
// if(person.empty()){
//     cout<<"NO"<<endl;
//     return;
// }
// if(!monster.empty()){
//    check_m=true;
// }
  //first row
  int mini_step=INT_MAX;
    for(int i=0;i<m;i++){
        if(g[0][i]!='#'){
           if(check_m&&(dis_p[0][i]<dis_m[0][i]|| dis_m[0][i]==-1)){
              mini_step=min(mini_step,dis_p[0][i]);
           }else if(!check_m){
               mini_step=min(mini_step,dis_p[0][i]);
           }
              
           }
        }
    //last row
    for(int i=0;i<m;i++){
        if(g[n-1][i]!='#'){
            if(check_m&&(dis_p[n-1][i]<dis_m[n-1][i]||dis_m[n-1][i]==-1)){
              mini_step=min(mini_step,dis_p[n-1][i]);
           }else if(!check_m){
               mini_step=min(mini_step,dis_p[n-1][i]);
           }
        }
    }
    //first column
    for(int i=0;i<n;i++){
        if(g[i][0]!='#'){
            if(check_m&&(dis_p[i][0]<dis_m[i][0]||dis_m[i][0]==-1)){
                mini_step=min(mini_step,dis_p[i][0]);
            }else if(!check_m){
                mini_step=min(mini_step,dis_p[i][0]);
            }
        }
    }
    //last column
       for(int i=0;i<n;i++){
        if(g[i][m-1]!='#'){
            if(check_m&&(dis_p[i][m-1]<dis_m[i][m-1]||dis_m[i][m-1]==-1)){
                mini_step=min(mini_step,dis_p[i][m-1]);
            }else if(!check_m){
                mini_step=min(mini_step,dis_p[i][m-1]);
            }
        }
    }
    if(mini_step==INT_MAX||mini_step<0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<mini_step<<endl;
    }
    

 }

signed main(){
    solve();
}