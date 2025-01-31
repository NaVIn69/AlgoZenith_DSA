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
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    for(int i=0;i<n;i++){
       if(v[i]!=0){
        int l=i+1;
        int per=l-v[i];
        if(l%per==0){
            cout<<l<<" "<<l/per<<endl;
        }

       }
    }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    while(t<=test){
        cout<<"Test case#"<<t<<endl;
        solve();
        t++;
    }
}