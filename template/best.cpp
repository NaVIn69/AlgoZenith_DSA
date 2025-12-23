#include <bits/stdc++.h>
using namespace std;

#define fori(i, S, N) for (int i = (S); i < (N); ++i)
#define rfori(i, S, N) for (int i = (S); i > (N); --i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define cina(a, n)              \
    for (int i = 0; i < n; ++i) \
    cin >> (a)[i]
#define coutaa(a, n, m)               \
    for (int i = 0; i < n; ++i)       \
    {                                 \
        for (int j = 0; j < m; ++j)   \
            cout << (a[i][j]) << " "; \
        cout << endl;                 \
    }
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define qb pop_back
#define yes(a) cout << (((a) > 0) ? "Yes" : "No") << endl
#define first(a) cout << (((a) > 0) ? "First" : "Second") << endl
#define ff first
#define ss second
#define ll long long
#define pt(x) cout << (x) << endl;
#define INF (ll)(1e18 + 7)
#define cmax(a, b) a = max(a, (b))
#define cmin(a, b) a = min(a, (b))
#define str string

template <typename T1, typename T2>
istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin >> a.first >> a.second; }
template <typename T1>
istream &operator>>(istream &cin, vector<T1> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename T1>
istream &operator>>(istream &cin, valarray<T1> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout << a.first << ' ' << a.second; }
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename T1>
ostream &operator<<(ostream &cout, const vector<T1> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
template <typename T1, typename T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

template <typename T1, typename T2>
std::pair<T1, T2> &operator+=(std::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
    lhs.first += rhs.first;
    lhs.second += rhs.second;
    return lhs;
}

template <typename T1, typename T2>
std::pair<T1, T2> &operator-=(std::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
    lhs.first -= rhs.first;
    lhs.second -= rhs.second;
    return lhs;
}

template <typename T1, typename T2>
std::pair<T1, T2> operator-(const std::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

namespace nt
{
    ll const N = 1e5 + 10;
    vi isPrime(N, 1);
    vi lprimef(N, -1);
    // vi hprimef(N, -1);
    vi primes;
    void seive(int n)
    {
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
                lprimef[i] = i;
                // hprimef[i] = i;
                for (int j = i * 2; j < n; j += i)
                {
                    isPrime[j] = 0;
                    if (lprimef[j] == -1)
                        lprimef[j] = i;
                    // hprimef[j] = i;
                }
            }
        }
    }

    map<ll, ll> factorization(ll n)
    {
        map<ll, ll> ans;
        while (n > 1)
        {
            ans[lprimef[n]]++;
            n /= lprimef[n];
        }
        return ans;
    }
    vector<ll> primeFactors(ll n)
    {
        vector<ll> ans;
        while (n > 1)
        {
            ll x = lprimef[n];
            n /= x;
            if (n % x != 0)
            {
                ans.pb(x);
            }
        }
        return ans;
    }

    int count_digit(int n) { return floor(log10(n) + 1); }

    bool isPow2(ll n) { return n && (!(n & (n - 1))); }

    ll nearestPow2(ll n) { return 1ll << ((ll)log2(n) + 1); }

    ll ncr(ll n, ll r)
    {
        ll x = 1, y = 1;
        fori(i, n - r + 1, n + 1)
        {
            x *= i;
        }
        fori(i, 1, r + 1)
        {
            y *= i;
        }
        return x / y;
    }

    bool isBitSet(ll n, ll i) { return (n >> i) & 1; }

    void setBit(ll &n, ll i) { n |= (1 << i); }

    void unsetBit(ll &n, ll i) { n &= (~(1 << i)); }

    void toggleBit(ll &n, ll i) { n ^= (1 << i); }

    ll euler_totient(ll n)
    {
        ll result = n;
        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    }

    // void phi_1_to_n(int n) {
    //     vector<int> phi(n + 1);
    //     for (int i = 0; i <= n; i++)
    //         phi[i] = i;

    //     for (int i = 2; i <= n; i++) {
    //         if (phi[i] == i) {
    //             for (int j = i; j <= n; j += i)
    //                 phi[j] -= phi[j] / i;
    //         }
    //     }
    // }

    ll bin_exp(ll a, ll b, ll M = 1e18 + 10)
    {
        a %= M;
        ll ans = 1;
        while (b)
        {
            if (b & 1)
            {
                ans = ans * a % M;
            }
            a = a * a % M;
            b >>= 1;
        }
        return ans;
    }

    ll mmi(ll a, ll b, ll M, bool isPrimeM = true)
    {
        if (__gcd(a, b) != 1)
        {
            cout << "Not Possible" << endl;
            return 1e18;
        }
        if (isPrimeM)
            return bin_exp(a, b - 2, M);
        return bin_exp(a, euler_totient(b) - 1, M);
    }

    vector<ll> getDivs(ll x)
    {
        vector<ll> divs;
        for (ll i = 1; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                divs.push_back(i);
                divs.push_back(x / i);
            }
        }
        sort(divs.begin(), divs.end());
        return divs;
    }
    vector<vector<ll>> getCombinations(ll n, ll k)
    {
        vector<vector<ll>> possibilities;
        vector<ll> start(k + 1);
        fori(i, 1, k + 1) start[i] = i;
        vector<ll> end(k + 1);
        fori(i, n - k + 1, n + 1) end[i - (n - k)] = i;
        while (1)
        {
            possibilities.pb(start);
            ll i = k;
            while (i >= 0 && start[i] == n - k + i)
            {
                i--;
            }
            if (i <= 0)
            {
                break;
            }
            start[i]++;
            for (ll j = i + 1; j <= k; ++j)
            {
                start[j] = start[j - 1] + 1;
            }
        }
        return possibilities;
    }

    vector<ll> getDigits(ll num)
    {
        vector<ll> digits;
        if (num == 0)
        {
            digits.push_back(0);
            return digits;
        }
        while (num > 0)
        {
            ll digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        return digits;
    }

    bool checkPalNum(ll n)
    {
        ll reverse = 0, temp = n;
        while (temp != 0)
        {
            reverse = (reverse * 10) + (temp % 10);
            temp = temp / 10;
        }
        return (reverse == n);
    }
    ll getMid(ll s, ll e) { return s + (e - s) / 2; }
    ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }
    ll gcd(vector<ll> &v)
    {
        if (!v.size())
            return 1;
        ll g = v[0];
        fori(i, 1, v.size())
        {
            g = __gcd(g, v[i]);
        }
        return g;
    }
    bool isvowel(char x) { return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'); }
    ll mex(vector<ll> &arr)
    {
        sort(arr.begin(), arr.end());
        ll mex = 0;
        for (ll idx = 0; idx < arr.size(); idx++)
            if (arr[idx] == mex)
                mex += 1;
        return mex;
    }
    // note:
    // fori(i, 0, n) s[i] = tolower(s[i]);								  // Converting to lowercase
    // s.resize(distance(s.begin(), unique(s.begin(), s.end())));         // Removing duplicates
};
using namespace nt;

void solve(ll t)
{
    ll n; cin >> n;
    vector<ll> a(n); cin >> a;
    ll ct = 0;
    ll ans = n;
    vll arr(n, 0);
    arr[0] = a[0];
    fori(i, 1, n){
        arr[i] = min(arr[i-1], a[i]);
    }
    rfori(i, n-1, -1){
        if(a[i] == arr[i]){
            ct++;
            ans = min(ans, n-ct + a[i]);
        }
    }
    cout<<ans<<endl;
}

int main()
{

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve(t);
    }
}