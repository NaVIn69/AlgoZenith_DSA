#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
   
    // here we are making prefix array by 1 based index array
    // +2 size is increased because due to 0th index we increase 1 and x2+1||y2+1 due to which i increase 1
    int p[n+2][m+2];
    for( int i=0;i<n+2;i++ ){
        for(int j=0;j<m+2;j++){
            p[i][j]=0;
        }
      
    }
    // here we are making the 2d prefix array
   while(q--){
    int x1,y1,x2,y2,c;
    cin>>x1>>y1>>x2>>y2>>c;
    
    p[x1][y1]+=c;
    p[x1][y2+1]-=c;
    p[x2+1][y1]-=c;
    p[x2+1][y2+1]+=c;
   }
   int maxi=INT_MIN;
   for(int i=1;i<n+1;i++){
    int mini_maxi=INT_MIN;
    for(int j=1;j<m+1;j++){
        p[i][j]=p[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        mini_maxi=max(mini_maxi,p[i][j]);
    }
    maxi=max(mini_maxi,maxi);
   }
   // here we are counting the cell with max_element
   int cnt=0;
   for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
        if(p[i][j]==maxi) cnt++;
    }
   }
   cout<<maxi<<" "<<cnt<<endl;
  
    
  



}
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
    // cin>>t;
     while(t--){
        solve();
     }
}