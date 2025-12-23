#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int mod=1e9+7;
void solve(){
   int n;
   cin>>n;
   string s;
   cin>>s;
   if(s.size()==1){
    cout<<"0"<<endl;
    return;
   }
   int cnt=0;
   int ans=0;
   for(int i=1;i<n;i++){
     if(s[i]==s[i-1]){
        cnt++;
     }else{
        ans+=cnt;
        cnt=0;
     }
   }
   ans+=cnt;
   cout<<ans<<endl;


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
