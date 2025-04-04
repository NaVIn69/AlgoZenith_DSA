#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int a, b;
vector<int> is_prime;

void sieve_of_eratosthenes() {
    // first we calculate all the prime number 1 to sqrt(b). after that 
    int limit = sqrt(b) + 1; // here limit to find prime in between a to b
    vector<int> small_prime(limit + 1, 1); // normal sieve_eratosthenes , to find all the prime number from 1 to sqrt(b)
    vector<int> prime; // here we store all the prime number from 1 to sqrt(b)

    // Find small primes up to sqrt(b)
    for (int i = 2; i * i <= b; i++) {
        if (small_prime[i]) {
            prime.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                small_prime[j] = 0;
            }
        }
    }

    // Initialize range [a, b] as all prime (1 means prime)
    is_prime.assign(b - a + 1, 1);

    // Mark non-primes using small primes
    for (auto x : prime) {
        int curMul = max(x*x,((a+x-1)/x)*x);  // First multiple of x in range
        // here we are going through all the multiple of that prime number

        for (int j = curMul; j <= b; j += x) {
            is_prime[j - a] = 0;
        }
        
    }

    // Edge case: If `a` is 1, mark it as not prime
    if (a == 1) is_prime[0] = 0;
}

void solve() {
    cin >> a >> b;
    sieve_of_eratosthenes();

    for (int i = a; i <= b; i++) {
        if (is_prime[i - a]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

signed main() {
    solve();
}
