#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=LONG_LONG_MAX;
    for(int j=0;j<n;j++){
        int i=0;
        int k=n-1;
        int sum=0;
        while(i<j&&j<k){
             sum=a[i]+a[j]+a[k];
            ans=min(ans,abs(sum-target));
            if(sum==target){
                cout<<"0"<<endl;
                return;
            }else if(sum>target){
               k--;
            }else{
                i++;
            }
        }
        
    }
    cout<<ans<<endl;

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