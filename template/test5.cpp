#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check_isprime(int n){
    if(n<=1) return 0;

  for(int i=2;i*i<=n;i++){

    if(n%i==0) return 0;
  }
  return 1;
}
void solve(){
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 int index_first=-2;
 for(int i=0;i<n;i++){
    if(check_isprime(arr[i])){
        index_first=i;
        break;
    }
 }
 int index_last=-3;
 for(int i=n-1;i>=0;i--){
    if(check_isprime(arr[i])){
        index_last=i;
        break;
    }
 }
 if(index_first==-2&&index_last==-3){
    cout<<"-1"<<endl;
 }
 else{
    cout<<index_last-index_first<<endl;
 }

}
signed main(){
    solve();

}