#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
void solve(){
    cin>>n;
    int arr[n],prr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    for(int i=0;i<n;i++){
        cin>>prr[i];
    }
    bool check=true;
   //right direction
   bool check_right=true;
   int index_right=0;
   for(int i=0;i<n;i++){
    if(i==n-1) continue;
      if(prr[i]>=prr[i+1]&&prr[i]-prr[i+1]>=arr[i+1]-arr[i]){
         continue;
      }else if(prr){
       
      }
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