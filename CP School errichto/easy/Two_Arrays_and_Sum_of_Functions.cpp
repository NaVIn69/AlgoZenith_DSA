#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int MOD=998244353;

void solve(){
    int n;
    cin>>n;
    int arr[n+1], brr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>brr[i];

    // sort b in DESCENDING directly (no reverse with wrong bounds)
    sort(brr+1, brr+n+1, greater<int>());

    int crr[n+1];
    for(int i=1;i<=n;i++){
        crr[i] = arr[i] * i * (n - i + 1); // no mod before sorting
    }

  
    sort(crr+1, crr+n+1);

    // sum over 1..n (not 0..n-1)
    int sum = 0;
    for(int i=1;i<=n;i++){
        int add = ((crr[i] % MOD) * (brr[i] % MOD)) % MOD;
        sum += add;
        if (sum >= MOD) sum -= MOD;
    }
    cout << (sum % MOD + MOD) % MOD << endl;
}

signed main(){
    solve();
}
