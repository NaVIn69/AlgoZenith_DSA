#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int arr[100100];
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int prefix[n];
  for(int i=0;i<n;i++){
    prefix[i]=arr[i];
    if(i){
        prefix[i]+=prefix[i-1];
    }
  }
}
int main(){
    solve();
}