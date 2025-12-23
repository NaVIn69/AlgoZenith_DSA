#include<bits/stdc++.h>
using namespace std;
#define in long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int a[n];
    int mini=INT_MAX;
    int maxi=INT_MIN;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
        mpp[a[i]]++;
    }
    
    


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}