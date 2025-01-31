// we can use the prefix xor array
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    int prefix[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i]=arr[i];
        if(i) prefix[i]^=prefix[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(l==0) cout<<prefix[r]<<endl;
        else cout<<(prefix[r]^prefix[l-1])<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}