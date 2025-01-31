#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //  int n=arr.size();
        vector<int>nsi(n);
        vector<int>psi(n);
        for(int i=n-1;i>=0;i--){
            nsi[i]=i+1;
            while(nsi[i]!=n&&arr[nsi[i]]>arr[i]){
                nsi[i]=nsi[nsi[i]];
            }

        }
        for(int i=0;i<n;i++){
            psi[i]=i-1;
            while(psi[i]!=-1&&arr[i]<=arr[psi[i]]){
                psi[i]=psi[psi[i]];
            }
        }
       int ans=0;
        for(int i=0;i<n;i++){
         int  k=(i-psi[i])*(nsi[i]-i);
         
          ans+=arr[i]*k;
            ans=ans;
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