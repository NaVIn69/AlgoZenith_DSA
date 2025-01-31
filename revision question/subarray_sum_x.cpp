#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    int cnt=0;
    map<int,int>mpp;
    mpp[sum]=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int rem=sum-x;
        if(mpp.find(rem)!=mpp.end()){
           cnt+=mpp[rem];
        }
        mpp[sum]++;
    }

}
signed main(){
    solve();
}