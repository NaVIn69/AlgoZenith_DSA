#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m;
int arr[1005][1005];
int prefix[1005][1005];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            prefix[i][j]=arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }

int q;
cin>>q;
while(q--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans=prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
    int area=(x2-x1+1)*(y2-y1+1);
    if(area==ans){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }
}


}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}