#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ngi[n];
    // next greater element in the right side
    // in ngi we push element by one based index
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&a[st.top()]<=a[i]){
            st.pop();
        }
        if(st.empty()){
            ngi[i]=n+1;
        }else{
            ngi[i]=st.top()+1;
        }
        st.push(i);
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