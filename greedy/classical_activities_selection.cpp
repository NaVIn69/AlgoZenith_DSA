/*Given n job activities with their start time and finish time. Find the maximum number of activities that can be performed without performing two activities at the same time.

Example:

Start = {5, 1, 3, 0, 5, 8}, end = {9, 2, 4, 6, 7, 9}  => 4
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool cmp(pair<int,int>&a,pair<int,int>&b){
      return a.second<b.second;
}
void solve(){
    int n;
    cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    // sort by end;
    sort(arr,arr+n,cmp);

    int max_no_job=0;
    int prev_end=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i].first>=prev_end){
            max_no_job++;
            prev_end=arr[i].second;
        }
    }
    cout<<max_no_job<<endl;

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