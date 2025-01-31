#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
void solve(){
cin>>n;
for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
int res=INT_MAX;
for(int i=1;i<n;i++){
    res=min(res,a[i]^a[i-1]);
}
cout<<res<<endl;


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}