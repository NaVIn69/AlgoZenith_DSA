#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct DSU {
    int n;
    int cnt;
    vector<int> parent, rank;

    DSU(int a) {
        n = a;
        cnt = a;
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] >= rank[y]) {
                parent[y] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            cnt--; // Reduce component count
        }
    }

    void reset() {
        cnt = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
};

void solve() {
    int n, m,q;
    cin >> n >> m>>q;

    vector<pair<int, int>> edge(m + 1);  // Fix size (1-based indexing)
    vector<bool> marked(m + 1, false);
    vector<pair<int, int>> query;
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edge[i] = {a, b};  // Fix out-of-bounds issue
    }

    
    query.resize(q);

    for (int i = 0; i < q; i++) {
        int ch, x = -1;
        cin >> ch;
        if (ch == 1) {
            cin >> x;
            query[i] = {1, x};
           marked[x]=true;
        } else {
            query.push_back({2, -1});
        }
    }

    DSU u(n);

    // Merge edges that were NOT removed
    for (int i = 1; i <= m; i++) {
        if (!marked[i]) {  
            u.merge(edge[i].first, edge[i].second);
        }
    }

    vector<int> ans;

    for (int i = q - 1; i >= 0; i--) {
        if (query[i].first == 1) {
            int x = query[i].second;
            // if (x >= 1 && x <= m) {
                u.merge(edge[x].first, edge[x].second);
            // }
        } else {
            ans.push_back(u.cnt);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int num : ans) {
        cout << num << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
