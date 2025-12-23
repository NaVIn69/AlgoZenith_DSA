#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
     int n;
     cin>>n;
     vector<string>name(n);
     int cnt[26]={0};
     for(int i=0;i<n;i++){
           cin>>name[i];
           cnt[name[i][0]-'a']++;
     }
     int ans=0;
   
     for(int i=0;i<26;i++){
         if(cnt[i]>2){
             int a=cnt[i]/2;
             int b=cnt[i]-a;
             ans+=((a*(a-1))/2);
             ans+=((b*(b-1))/2);
         }
     }
     cout<<ans<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}