#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int a[n];
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mini=min(mini,abs(a[i]));
    }
    cout<<mini<<endl;

}
int main(){
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}