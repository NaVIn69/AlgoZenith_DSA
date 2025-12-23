#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> v;
int n;
bool ok(ll d) {
    ll last = -(1LL<<60);
    int c = 0;
    for (auto &p : v) {
        ll x = max(p.first, last + d);
        if (x <= p.second) {
            last = x;
            if (++c == n) return true;
        }
    }
    return false;
}
int main() {
    cin>>n;
    v.resize(n);
    ll mn = (1LL<<62);
     ll mx = -(1LL<<62);
    for (int i=0;i<n;i++){
        ll a,b; cin>>a>>b;
        v[i]={a,b}; 
        mn=min(mn,a);
        mx=max(mx,b);
    }
    sort(v.begin(), v.end(), [](auto &x, auto &y){ 
        return x.second < y.second; 
    });

    ll lo=0, hi=mx-mn, ans=0;
    while (lo<=hi){
        ll mid=(lo+hi)/2;
        if (ok(mid)){

        ans=mid, lo=mid+1;
    } else{

     hi=mid-1;
    }
    }
    cout << ans << "\n";
    return 0;
}
