#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// int n,k;
// int arr[100100];
void solve(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    set<int>st;
    int suffix_mex[n];
    int a=0;
    for(int i=n-1;i>=0;i--){
       st.insert(arr[i]);
     
        while(st.count(a)){
          a++;
       }
       suffix_mex[i]=a;

       
    }
    for(int i=0;i<n;i++){
        cout<<suffix_mex[i]<<" ";
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