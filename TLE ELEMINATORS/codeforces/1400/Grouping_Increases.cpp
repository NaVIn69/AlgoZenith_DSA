#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"

int longest_increasing(vector<int>&a) {
    if (a.empty()) return 0;
    vector<int> tail;                 // tail[k] = min possible tail of an inc subseq of length k+1
    tail.reserve(a.size());
    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x); // strict LIS -> lower_bound
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return (int)tail.size();
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int l=longest_increasing(arr);

    cout<<max(0LL,l-2)<<endl;
  

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}