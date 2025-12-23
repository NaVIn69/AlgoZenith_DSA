#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> pos[n+1];
    for(int i=0;i<n;i++){
        pos[b[i]].push_back(i);
    }
    for(int k=1;k<=n;k++){
        if((int)pos[k].size()%k!=0){
            cout<<-1<<endl;
            return ;
        }
    }

    vector<int>a(n, 0);
    int l=1;
    for(int k=1;k<=n;k++) {
        auto &v=pos[k];
        for(int i=0;i<(int)v.size(); i+=k) {
            for(int j=0;j<k; j++)a[v[i + j]]=l;
            l++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}