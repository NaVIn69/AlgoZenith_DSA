#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head=-1;
    int tail=0;
    int cnt=0;
    int ans=0;
    while(tail<n){
        while(head+1<n && (arr[head+1]==1||cnt<k)){
            head++;
            if(arr[head]==0){ 
                cnt++;
            }
        }
        int len=head-tail+1;
        ans=max(ans,len);
        if(tail<=head){
            if(arr[tail]==0){ 
            cnt--;
            }
            tail++;
        }else{
            tail++;
            head=tail-1;
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