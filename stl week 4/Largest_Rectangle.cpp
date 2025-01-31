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
   int nsi[n],psi[n];
   for(int i=n-1;i>=0;i--){
    nsi[i]=i+1;
    while(nsi[i]!=n&&a[nsi[i]]>=a[i]){
             nsi[i]=nsi[nsi[i]];
    }
   }
   for(int i=0;i<n;i++){
    psi[i]=i-1;
    while(psi[i]!=-1&&a[i]<=a[psi[i]]){
        psi[i]=psi[psi[i]];
    }

   }
  // here of histogram
  int maxi=0;
  for(int i=0;i<n;i++){
    int k=psi[i]+1;
    int p=nsi[i];
    int common_area=(p-k)*a[i];
    maxi=max(maxi,common_area);
  }
  cout<<maxi<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}