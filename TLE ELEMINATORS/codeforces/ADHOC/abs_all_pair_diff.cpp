#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;

void solve(){
    cin>>n;
    vector<int>v;
    int prev=-1e9;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
       
            v.push_back(x);
            sum+=x;
       
    }
    int ans=0;
    int m=v.size();
    for(int i=m-1;i>=0;i--){
         ans+=(v[i]*i-(sum-v[i]));
         sum-=v[i];
    }
    cout<<ans<<endl;

    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}