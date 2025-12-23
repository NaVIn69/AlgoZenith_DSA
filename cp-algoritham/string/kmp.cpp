#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>lps(string s){
    vector<int>v(s.size(),0);
    int pre=0;
    int suff=1;
    while(suff<s.size()){
        // matched
        if(s[suff]==s[pre]){
            v[suff]=pre+1;
            pre++;
            suff++;
        }else{
            // not matched
            if(pre==0){
                v[suff]=0;
                suff++;
            }else{
              pre=v[pre-1];
            }

        }
    }
    return v;
}
void solve(){
    string s;
    cin>>s;
    vector<int>v=lps(s);
    for(int i=0;i<s.size();i++){
        cout<<v[i]<<" ";
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
