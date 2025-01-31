#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // pointers
    int head=-1,tail=0;
    // datastrcutre
    int cnt0 = 0;

    int ans = 0;
    // TP: O(N*(H+A+T))
    
    while(tail<n){
        // eat as many element as possible.
        while(head+1<n && (arr[head+1]==1||cnt0<k)){
            // O(H)
            head++;
            if(arr[head]==0)cnt0++;
        }
        // save the current best length for this tail.
        // O(A)
        int len = head-tail+1;
        ans = max(ans,len);
        // move tail one step forward.
        // O(T)
        if(tail<=head){
            if(arr[tail]==0)cnt0--;
            tail++;
        }else{ // when empty
            tail++;
            head = tail-1; // set window as 0 length empty.
        }   
    }

    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}