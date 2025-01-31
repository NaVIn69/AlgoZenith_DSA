#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto&i:arr) cin>>i;
   map<int,int>mpp1;
   for(int i=0;i<n;i++){
    mpp1[arr[i]]++;
   }
   int k=mpp1.size();
   // take two pointer
   // pointers
    int head=-1,tail=0;
    // datastrcutre
    map<int,int>mpp;
    int dist_cnt=0;

    int ans =INT_MAX;
    // TP: O(N*(H+A+T))
    
    while(tail<n){
        // eat as many element as possible.
        while(head+1<n && (mpp[arr[head+1]]==0||dist_cnt<k)){
            // O(H)
            if(mpp[arr[head+1]]==0) dist_cnt++;
            mpp[arr[head+1]]++;
            head++;
        }
        // save the current best length for this tail.
        // O(A)
        int len = head-tail+1;
       if(dist_cnt==k){
        ans=min(ans,len);
       }
       
        // move tail one step forward.
        // O(T)
        if(tail<=head){
            mpp[arr[tail]]--;
            if(mpp[arr[tail]]==0) dist_cnt--;
            tail++;
        }else{ // when empty
            tail++;
            head = tail-1; // set window as 0 length empty.
        }  
       
    }

    cout<<ans<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}