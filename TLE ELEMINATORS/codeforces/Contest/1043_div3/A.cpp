#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    int m;
    cin>>m;
    string b,c;
    cin>>b>>c;
   
    string ans = a;
     for(int i=0;i<m;i++){
        if(c[i]=='V'){
            ans.insert(ans.begin(),b[i]);
        }else{
            ans.push_back(b[i]);
        }
     }
     cout<<ans<<endl;
    
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}