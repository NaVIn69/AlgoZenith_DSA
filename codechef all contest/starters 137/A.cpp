#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//int n;
//pair<int,int> arr[100100];
void solve(){
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i].first=a;
        arr[i].second=b;
    }
    sort(arr,arr+n);
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val=arr[i].first*arr[j].second+arr[i].second*arr[j].first;
              maxi=max(maxi,val);
        }
    }
    cout<<maxi<<endl;

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