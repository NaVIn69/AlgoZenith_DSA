#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int maxi = 2000000; // larger sieve range
int is_prime[2000010];
int sq_prime[2000010];
vector<int> primes;

void sieve() {
    for (int i = 2; i <= maxi; i++) is_prime[i] = 1;

    for (int i = 2; i * i <= maxi; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxi; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= maxi; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            sq_prime[i] = i * 1LL * i; // store square
        }
    }
}

// the prime number larger than maxi , we checking using the prime number from 2 t0 10^7 
// multiple of that prime is not my prime number 
bool isPrimeLL(int x) {
    if (x <= maxi) return is_prime[x];
    for (int p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    for (int p : primes) {
        if (1LL * p * p > n) break; // no need to check further
        int val = 1LL * p * p;
        if (n % val == 0) {
            int rem = n / val;
            if (isPrimeLL(rem)) {
                cout << p << " " << rem << endl;
                return;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    sieve();
    while (t--) {
        solve();
    }
}
