#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
   int arr[n];
   int i=0;
   int j=n-1;
   int k=1;
   while(i<=j){
        arr[i]=k++;
        if(i==j) break;
        arr[j]=k++;
        i++;
        j--;
   }
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
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