#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    while(q--){
        int k;
        cin>>k;
        int brr[k];
        for(int i=0;i<k;i++){
            brr[i]=arr[i];
        }
        if(k==1){
            cout<<brr[0]<<" ";
            continue;
        }
       sort(brr,brr+k);
    int op=(k+2-1)/2-1;
    int sum_start=0;
    // for(int i=0;i<op;i++){
    //     sum_start+=brr[i];
    // }
    // int last_sum=0;
    // for(int i=op;i<k;i++){
    //     last_sum+=brr[i];
    // }
    for(int i=1;i<k;i++){
        brr[i]=brr[i]+brr[i-1];
    }
    
  
    cout<<brr[k-1]-2*brr[op-1]<<" ";
    }



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