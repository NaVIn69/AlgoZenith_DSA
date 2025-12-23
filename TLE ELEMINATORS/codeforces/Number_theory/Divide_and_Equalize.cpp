#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<int> prime;
int is_prime[2000200];
int maxi = 1000000;

void sieve(int n) {
    for (int i = 2; i <= n; i++) is_prime[i] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i * 1LL * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int,int> freq; // prime -> total exponent count

    for (int i=0;i<n;i++){
         int x = arr[i];
         for (int p : prime) {
            if (1LL * p * p > x) break;
            while (x % p == 0) {
                freq[p]++;
                x /= p;
            }
        }
        if (x > 1) freq[x]++; // leftover prime
    }

    for (auto kv : freq) {
        if (kv.second % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(maxi);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
