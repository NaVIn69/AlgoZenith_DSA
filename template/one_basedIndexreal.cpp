
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
  ll n, k, q, i, a, b, x;
  cin >> n >> k >> q;
  // for 1 based index to perform it will take size +1 array then it perform from index first
  vector<ll> v(n + 1), pre(n + 2, 0), dp(n);
  vector<pair<ll, ll> > suf;

  for (i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (i = 0; i < k; i++) {
    cin >> a >> b;
    pre[a] += 1;
    pre[b + 1] -= 1;
  }

  for (i = 1; i <= n; i++) {
    if (i != 0) {
      pre[i] = pre[i - 1] + pre[i];
      suf.push_back({v[i], pre[i]});
    }
  }
  sort(suf.begin(), suf.end());
  for (i = 0; i < n; i++) {
    if (i == 0)
      dp[i] = suf[i].second;
    else
      dp[i] = dp[i - 1] + suf[i].second;
  }
  for (i = 0; i < q; i++) {
    cin >> a;
    if (lower_bound(dp.begin(), dp.end(), a) != dp.end()) {
      x = lower_bound(dp.begin(), dp.end(), a) - dp.begin();
      cout << suf[x].first << " ";
    } else {
      cout << "-1 ";
    }
  }
  cout << endl;
}

int main() {
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, T;

  T = 1;
  cin >> T;

  for (i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _; cin >> _;
    while(_--) {
        int n, m, q;
        cin >> n >> m >> q;
        pair<int,int> A[n];
        for(int i = 0; i < n; i++) {
            cin >> A[i].first;
            A[i].second = 0;
        }
        for(int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            l--; r--;
            A[l].second++;
            if(r + 1 < n) A[r + 1].second--;
        }
        for(int i = 1; i < n; i++)
            A[i].second += A[i - 1].second;

        sort(A, A + n);

        int ans[q];
        pair<ll,int> Q[q];
        for(int i = 0; i < q; i++) {
            cin >> Q[i].first;
            Q[i].second = i;
        }

        sort(Q, Q + q);

        int ptr = 0;
        ll sum = 0;

        for(int i = 0; i < q; i++) {
            ll x = Q[i].first;
            while(ptr < n && sum + A[ptr].second < x) {
                sum += A[ptr].second;
                ptr++;
            }
            if(ptr < n) ans[Q[i].second] = A[ptr].first;
            else ans[Q[i].second] = -1;
        }

        for(int i = 0; i < q; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}*/