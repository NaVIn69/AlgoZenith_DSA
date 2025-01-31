#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>vis,dis_m,dis_p;
vector<vector<state>>parent;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
void multisource_bfs(){
      vis.assign(n+1,vector<int>(m+1,0));
     dis_m.assign(n+1,vector<int>(m+1,1e9));
     dis_p.assign(n+1,vector<int>(m+1,1e9));
    //  parent.assign(n+1,vector<state>(m+1,{-1,-1}));
    queue<state>q_m;
    queue<state>q_p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='M'){
                dis_m[i][j]=0;
                q_m.push({i,j});
            }else if(g[i][j]=='A'){
                dis_p[i][j]=0;
                q_p.push({i,j});
            }
        }
    }
    /// here we have all the sources inside my queue
    // now each sources ke liye bfs lagega
     // monster ke liye shortest distance
    //  cout<<"size"<<q_m.size()<<" "<<q_p.size()<<endl;
     while(!q_m.empty()){
        
        state sc_node=q_m.front();
        q_m.pop();
        int xx=sc_node.first;
        int yy=sc_node.second;
        // normal bfs
        // dis_m[xx][yy]=0;
        // queue<state>q;
        // q.push(sc_node);
        // while(!q.empty()){
        //    state node=q.front();
        //    q.pop();
        //    int xx=node.first;
        //    int yy=node.second;
        //    if(vis[xx][yy]) continue;
        //    vis[xx][yy]=1;
           for(int i=0;i<4;i++){
            int nx=xx+dx[i];
            int ny=yy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
                if(dis_m[nx][ny]>dis_m[xx][yy]+1){
                    dis_m[nx][ny]=dis_m[xx][yy]+1;
                    q_m.push({nx,ny});
                }
            }
           }


        }
        //  vis.assign(n+1,vector<int>(m+1,0));
     
         while(!q_p.empty()){
        
        state sc_node=q_p.front();
        q_p.pop();
        int xx=sc_node.first;
        int yy=sc_node.second;
        // normal bfs
        // dis_p[x][y]=0;
        // queue<state>q;
        // q.push(sc_node);
        // while(!q.empty()){
        //    state node=q.front();
        //    q.pop();
        //    int xx=node.first;
        //    int yy=node.second;
        //    if(vis[xx][yy]) continue;
        //    vis[xx][yy]=1;
           for(int i=0;i<4;i++){
            int nx=xx+dx[i];
            int ny=yy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
                if(!vis[nx][ny]&&dis_p[nx][ny]>dis_p[xx][yy]+1){
                    dis_p[nx][ny]=dis_p[xx][yy]+1;
                    q_p.push({nx,ny});
                }
            }
           }


        }
     
    //  cout<<"monster"<<endl;
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis_m[i][j]<<" ";
    //     }
    //     cout<<endl;
    //  }
    //  cout<<"person"<<endl;
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis_p[i][j]<<" ";
    //     }
    //     cout<<endl;
    //  }
     // here we have all the shortest distance of the 
     // here we do the comparison of both distance of monster and person
     

     // tc -> O(p*n*m)+o(M*n*M) 
     // here we can improve the time complexity
     // here we are traversing all the 0 and m-1 column
     bool check =false;
     int ans=0;
     for(int i=0;i<n;i++){
        if(g[i][0]!='#'){
            // cout<<"0th column"<<dis_m[i][0]<<" "<<dis_p[i][0]<<endl;
            if(dis_p[i][0]<dis_m[i][0]){
               check=true;
               ans=dis_p[i][0];
               break;
            }
        }
             if(g[i][m-1]!='#'){
               
                // cout<<"m-1 th column"<<dis_m[i][m-1]<<" "<<dis_p[i][m-1]<<endl;
                if(dis_p[i][m-1]<dis_m[i][m-1]){
                    //  cout<<"navin"<<endl;
                    check=true;
                    ans=dis_p[i][m-1];
                    break;
                }
            }
        }
     
        if(check){
            cout<<"YES"<<endl;
            cout<<ans<<endl;
            return;
        }

        for(int i=0;i<m;i++){
        if(g[0][i]!='#'){
            if(dis_p[0][i]<dis_m[0][i]){
               check=true;
               ans=dis_p[0][i];
               break;
            }
        }
             if(g[n-1][i]!='#'){
                if(dis_p[n-1][i]<dis_m[n-1][i]){
                    check=true;
                    ans=dis_p[n-1][i];
                    break;
                }
            }
        }
        
        if(check){
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }else{
            cout<<"NO"<<endl;
        }


     }


void solve(){
  cin>>n>>m;
  g.resize(n+1);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char ch;
        cin>>ch;
        g[i].push_back(ch);
    }
  }
multisource_bfs();


}
signed main(){
    solve();
}