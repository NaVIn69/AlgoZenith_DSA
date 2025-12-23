#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s;
    cin>>s;
    int depth=0;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(depth<0&&s[i]=='('){
           ans+=abs(depth);
           depth=0;
        }
        if(s[i]=='(') depth++;
        else if(s[i]==')') depth--;
        
    }
    ans+=abs(depth);
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
