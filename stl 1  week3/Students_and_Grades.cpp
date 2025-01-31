#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
int n,m;
cin>>n>>m;
int a[n],b[m];
unordered_set<int>st;
for(int i=0;i<n;i++){
cin>>a[i];
st.insert(a[i]);
}
for(int i=0;i<m;i++){
    cin>>b[i];
}
for(int i=0;i<m;i++){
    if(st.find(b[i])!=st.end()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    st.insert(b[i]);
}
/*for(int i=0;i<m;i++){
    if(mpp[b[i]]>=1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    mpp[b[i]]++;
}*/
}
signed main(){
    ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}