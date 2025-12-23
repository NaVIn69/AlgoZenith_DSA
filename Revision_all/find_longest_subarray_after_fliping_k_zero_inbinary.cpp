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
    // two pointer to maintain the window 
    int cnt0=0;
    // data structure the maintain the window property
    int ans=0;
    // for store the best answer of every tail
    while(tail<n){
        // eat as many we can eat
        while(head+1<n&&(arr[head+1]==1||cnt0<k)){
            if(arr[head+1]==0) cnt0++;
            head++;
        }
        // best answer to store for this tail
        int len=head-tail+1;
        ans=max(ans,len);
        if(tail<=head){
            if(arr[tail]==0)cnt0--;
            tail++;
        }else{
            cout<<head<<" "<<tail<<endl;
            tail++;
            head=tail-1;
        }
    }
    cout<<ans<<endl;   v  

}
signed main(){
    solve();
}