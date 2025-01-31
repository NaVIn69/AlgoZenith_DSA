#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    int a[n];
    set<int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    cout<<st.size()<<'\n';


}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }


}