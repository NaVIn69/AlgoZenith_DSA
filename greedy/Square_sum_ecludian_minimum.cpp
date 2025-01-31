/*
You are given an array A of n non-negative integers.

Define function F = Summation of |Ai-X|2 for all i from 1 to n.

Find the minimum value of the function F by choosing an appropriate integer X.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    int total=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    double m=total/(double)n;
   int mean=floor(m);
   int mean1=ceil(total/n);
   int ans=0;
   int ans1=0;
   for(int i=0;i<n;i++){
    ans+=(1LL*(mean-arr[i])*(mean-arr[i]));
    ans1+=(1LL*(mean1-arr[i])*(mean1-arr[i]));
   }
   cout<<min(ans1,ans)<<endl;

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