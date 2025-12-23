#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int z=0;
    for(auto x:str){
         if(x=='0')z++;
    }
    int ans=0;
    for(int i=0;i<z;i++){
        if(str[i]=='1'){
            ans++;
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