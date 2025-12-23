#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
pair<int,int> arr[200200];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
    }
    sort(arr,arr+n);
    // why sorting is working 
    // a[i]<a[j] && b[i]>b[j] after swaping it also add 1 inversion to final
    // a[i]>a[j]&&b[i]>b[j] && after sorting it get removed 
     for(int i=0;i<n;i++){
        cout<<arr[i].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i].second<<" ";
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