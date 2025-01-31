#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int>st;
    for(int i=0;i<n+1;i++){
         st.insert(i);
    }
    for(int i=0;i<n;i++){
        if(st.count(arr[i])){
            st.erase(st.find(arr[i]));
        }
    }
    cout<<*st.begin()<<endl;
    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}