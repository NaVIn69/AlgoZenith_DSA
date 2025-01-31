#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head=-1,tail=0;
    //data structure to find maintain the window proprety
    map<int,int>mpp;
    int dist_cnt=0;

    // save 
    int ans=0;
    while(tail<n){
        // eat as many element as u can eat
        while(head+1<n && ((mpp.find(arr[head+1])!=mpp.end())||dist_cnt<k)){
           head++;
           if(mpp[arr[tail]]==0) dist_cnt++;
           mpp[arr[head]]++;
        }
        // save the current best answer for that tail
    int len=head-tail+1;
    // update the asnwer
    ans+=((len*(len+1))/2);
    // move the tail one step forward
    if(tail<=head){
       mpp[arr[tail]]--;
       if(mpp[arr[tail]]==0){
        dist_cnt--;
        // here
       
       }
       tail++;
    
    }else{
        // set the window length to 0
        tail++;
        head=tail-1;

    }
    }
    cout<<ans<<endl; 


}
signed main(){
    solve();
}