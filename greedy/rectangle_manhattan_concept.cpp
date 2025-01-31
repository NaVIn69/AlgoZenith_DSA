#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    vector<vector<pair<int,int>>>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            int x,y;
            cin>>x>>y;
            pair<int,int>p={x,y};
            v[i].push_back(p);
        }
    }
    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}