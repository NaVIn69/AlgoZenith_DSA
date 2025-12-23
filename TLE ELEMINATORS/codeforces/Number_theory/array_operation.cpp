#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto&x:arr){
        cin>>x;
    }
    sort(arr.rbegin(),arr.rend());
    int i=0,j=2*k-1;
    int contri=0;
    int cnt=0;
    while(i<j){
        if(arr[j]==arr[i])break;
        contri+=(arr[j]/arr[i]);
        i++;
        j--;
        cnt++;
    }

    // here we have equal element from i to j ,, deleting the 
    while(arr[j]==arr[i]){
          j++;
    }
    // from that j we have to move delete i
    
    for(int i=2*k;i<n;i++){
         contri+=arr[i];
    }
    cout<<contri<<endl;



}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}