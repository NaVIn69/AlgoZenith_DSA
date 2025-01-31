#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    set<int>st,nst,stu;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
        stu.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        nst.insert(b[i]);
        stu.insert(b[i]);
    }
    for(auto it=stu.begin();it!=stu.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    set<int>v;
    for(int i=0;i<n;i++){
        if(nst.find(a[i])!=nst.end()){
            cout<<a[i]<<" ";
        }else{
            v.insert(a[i]);
        }
    }
    cout<<endl;
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}