#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m;
int arr[200200];
int prefix[200200];
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
        if(i){
            prefix[i]=arr[i-1];
            prefix[i]+=prefix[i-1];
        }
    }
    while(m--){
        int x;
        cin>>x;
        int idx=lower_bound(prefix,prefix+n,x)-prefix;
        cout<<idx+1<<" "<<x-prefix[]<<endl;
    }

}
signed main(){
    solve();
}