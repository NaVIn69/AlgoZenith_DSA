#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    
    int n,k;
    cin>>n>>k;
    int arr[100100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head=-1,tail=0;
    // data structure to maintain the window
    map<int,int>mpp;
    int dist=0;

    // store the ans
    int ans=0;
    
    while(tail<n){
        // eat as many u can eat
        while(head+1<n&&((mpp.count(arr[head+1])>0))||dist<k){
            head++;
             if(mpp.count(k)){
                mpp[arr[head]]++;
             }else{
                dist++;
             }
        }
    }
}
signed main(){
    solve();
}