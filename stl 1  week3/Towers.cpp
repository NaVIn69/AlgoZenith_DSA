#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
multiset<int>st;
for(int i=0;i<n;i++){
    auto it=st.upper_bound(a[i]);
    if(it==st.end()){
        st.insert(a[i]);
    }else{
        st.erase(*it);
        st.insert(a[i]);
    }
}
cout<<st.size()<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}