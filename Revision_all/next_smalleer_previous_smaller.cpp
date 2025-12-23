#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int arr[100100]
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int nsi[n],psi[n];
  for(int i=n-1;i>=0;i--){
    nsi[i]=i+1;
    while(nsi[i]!=n&&arr[nsi[i]]>=arr[i]){

    }
  }
}
signed main(){
    solve();
}