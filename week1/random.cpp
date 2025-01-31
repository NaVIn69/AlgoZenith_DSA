#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define int long long
#define endl '\n'
int binary_exp(int a,int b){
    int ans = 1; // Takes order log(b) to run.
    while(b){
        if(b%2==1){
            ans= ans*a % mod;
        }
        a = a*a % mod;
        b/=2;
    }
    return ans;
}
int fact(int n){
    int ans = 1;
    for(int i=1;i<=n;i++){   // O(n)
        ans = (ans*i)%mod;
    }
    return ans;
}
void solve(){
    int n , m;
    cin>>n>>m;
    // We need to calculate fact(n+m)/fact(n)*fact(m)
    // A * (fact(n)*fact(m))inverse % mod
    // Aim is to calculate (fact(n)*fact(m) )inverse % mod
    // We knew (B)inverse % mod = (fact(n)*fact(m)raised to mod-2) % mod
    int ans = (fact(n+m)*binary_exp((fact(n)*fact(m))%mod , mod-2))%mod; // O(n+m)
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) solve();  // O(t*(n+m))
}