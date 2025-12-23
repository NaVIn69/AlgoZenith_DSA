#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,q;
int arr[1000100];
int brr[1000100];
void solve(){
    cin>>n>>q;
    while(q--){
        int a,d,l,r;
        cin>>a>>d>>l>>r;
        arr[l]+=(a-l*d);
        arr[r+1]-=(a-l*d);
        brr[l]+=d;
        brr[r+1]-=d;
    }
    // here my final array f[i]=arr[i]+brr[i]*i
    for(int i=1;i<=n;i++){
         arr[i]+=arr[i-1];
        arr[i]=arr[i]%mod;
         brr[i]+=brr[i-1];
         brr[i]=brr[i]%mod;
    }

    for(int i=1;i<=n;i++){
        int final_val=(arr[i]%mod+(i*brr[i])%mod)%mod;
        cout<<(final_val%mod+mod)%mod<<" ";
    }
    cout<<endl;





}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}