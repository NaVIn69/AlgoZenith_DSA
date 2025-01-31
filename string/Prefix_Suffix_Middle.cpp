#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int t=1;
vector<int>kmp(string pattern) {
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>v=kmp(s);
   int long_pre_suf=v[n-1];
   if(long_pre_suf==0){
    cout<<"-1"<<endl;
    return;
   }
   bool check=false;
   for(int i=n-2;i>=1;i--){
        if(long_pre_suf==v[i]){
            check=true;
            break;
        }
   }
   if(check){
    cout<<s.substr(0,long_pre_suf)<<endl;
    return;
    //here v[v[n-1]-1] jis length ka maximum prefix suffix mila hai usse just prefix wlala length ka check kr rhe hai
   }else if(v[v[n-1]-1]==0){
    cout<<"-1"<<endl;
    return;
   }else{
    cout<<s.substr(0,v[v[n-1]-1])<<endl;
   }

   }

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    while(t<=test){
        solve();
        t++;
    }
}