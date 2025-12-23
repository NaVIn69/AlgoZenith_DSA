#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;

int binary_exponentiation(int base, int exponent) {
    int result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int solve(int a, int b, int c, int d, int e, int f, int g, int h) {
    int term1 = binary_exponentiation(a, b);
    int term2 = c % mod;
    int term3 = (d * binary_exponentiation(e, mod - 2)) % mod; // Modular inverse of e
    int term4 = binary_exponentiation(f, g);
    int term5 = binary_exponentiation(term4, h);

    int result = (term1 - term2 - term3 + term5 + 2*mod) % mod;
    return result;
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){

    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;

    int answer = solve(a, b, c, d, e, f, g, h);

    cout << answer << endl;
    }

    return 0;
}
