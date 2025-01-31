#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
    cin>>n;
    int a[n];
    int ans=0;
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
      cin>>a[i];
        mpp[a[i]]++;
    }
    for(auto x:mpp){
if(x.second%2!=0){
cout<<x.first<<endl;
    break;
}
    }
    
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}