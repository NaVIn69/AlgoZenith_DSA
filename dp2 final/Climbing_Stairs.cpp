#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;

void solve(){
   cin>>n>>m;
   // here we have to take m steps
   int q=n/m;
   int r=n%m;
   // remainig step we have to go by using the one by one step
   cout<<(q+r)<<endl;

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