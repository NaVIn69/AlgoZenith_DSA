#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int r,c;
int arr[1005][1005];
int prefix[1005][1005];

void solve(){
  cin>>r>>c;
  for(int i=1;i<=r;i++){
     for(int j=1;j<=c;j++){
        cin>>arr[i][j];
     }
  }
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
        prefix[i][j]=arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
    }
  }
  // here prefix[i][j] tell me summ of the grid from (1,1) to (i,j)
  int q;
  cin>>q;
  while(q--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans=prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
    cout<<ans<<endl;
  }
}
signed main(){
    solve();

}