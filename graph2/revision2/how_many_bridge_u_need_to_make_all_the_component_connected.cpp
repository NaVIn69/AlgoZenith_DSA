#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
using state=pair<int,int>;
vector<vector<char>>g;
vector<vector<int>>dis;
void multiSource(){
    dis.assign(n+1,vector<int>(m+1,1e9));
    queue<state>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(g[i][j]=='1'||g[i][j]=='2'||g[i][j]=='3'){
               q.push({i,j});
               dis[i][j]=0;
           }
        }
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

}
signed main(){

}