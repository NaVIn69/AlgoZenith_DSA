#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int mod=1e9+7;
void solve(){
   int x, y;
   cin>>x>>y;
   int tot=x;
   for(int i=0;i<y;i++){
    if(1000+tot>2*tot){
        tot=1000+tot;
    }else{
        tot=(2*tot);
    }
   }
   cout<<tot<<endl;

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
