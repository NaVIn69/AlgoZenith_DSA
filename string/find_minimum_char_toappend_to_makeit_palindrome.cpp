#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> computePrefixFunction(string pattern) {
    int m = pattern.length();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k-1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}
void solve(){
   string s;
   cin>>s;
   string str=s;
   reverse(str.begin(),str.end());
   string x=s+'@'+str;
   vector<int>ans=computePrefixFunction(x);
   cout<<s.size()-ans[ans.size()-1]<<endl;

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