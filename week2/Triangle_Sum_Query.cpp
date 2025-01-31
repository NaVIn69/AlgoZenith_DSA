#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
     // rectangular prefix sum
     int p1[n+2][m+2]={0};
   /*  for(int i=0;i<m+1;i++){
        p1[0][i]=0;

      
    }
   
    for(int j=0;j<n+1;j++ ){
        p1[j][0]=0;
       
       
    }*/
    for(int i=2;i<n+2;i++){

        for(int j=2;j<m+2;j++){
           p1[i][j]=(((a[i-2][j-2]%mod+p1[i-2][j]%mod)%mod+p1[i][j-2]%mod)%mod-p1[i-2][j-2]%mod)%mod;
          
        }
    }



    int p[n+2][m+2]={0};
    for(int i=2;i<n+2;i++){
        for(int j=2;j<m+2;j++){
            p[i][j]=(((a[i-2][j-2]%mod+p[i-1][j-1]%mod)%mod+p[i-1][j]%mod)%mod-p[i-2][j-1]%mod)%mod;
        }
    }
    while(q--){
        int x,y,l;
        cin>>x>>y>>l;
        x++;
        y++;
        int ans=((p[x][y]-p[x-l][y-l])%mod-(p1[x-l][y]-p1[x-l][y-l])%mod)%mod;
        cout<<(ans%mod+mod)%mod<<endl;
    }


    
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    solve();

}