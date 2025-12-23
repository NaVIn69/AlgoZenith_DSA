#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   sort(arr.rbegin(),arr.rend());
   
   int sum=0;
   for(int i=0;i<n;i+=k){
       sum+=(2*(arr[i]-1));
   }
   cout<<sum<<endl;
}
signed main(){
    solve();
}