#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
long long p[N][N];
long long a[N][N];
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
  }

  long long max = a[1][1];
  long long count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      p[i][j] = a[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
      if (p[i][j] == max) {
        count++;
      } else if (p[i][j] > max) {
        max = p[i][j];
        count = 1;
      }
    }
  }

  cout << max << " " << count << '\n';
}

signed main() { solve(); }
// here ek maximum size ka prefix array and simple array le liya than uske badd one based index pe solve kr diya
