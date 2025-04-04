#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, m, q;
vector<pair<int, int>> edge;
vector<pair<int, int>> query;
vector<bool> marked;

struct DSU {
    int cnt;
    vector<int> parent, rank, size;

    DSU(int n) {
        cnt = n;
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot) {
            if (rank[xroot] > rank[yroot]) {
                parent[yroot] = xroot;
            } else if (rank[xroot] < rank[yroot]) {
                parent[xroot] = yroot;
            } else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
            cnt--; // Reduce connected components
        }
    }
};

void solve() {
    cin >> n >> m >> q;
    
    edge.resize(m + 1);
    query.resize(q);
    marked.resize(m + 1, false);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
    }

    for (int i = 0; i < q; i++) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int x;
            cin >> x;
            query[i] = {1, x};
            marked[x] = true;  // Mark edges to be removed
        } else {
            query[i] = {2, -1};
        }
    }

    DSU u(n);
    
    // Process all edges that were not marked as removed
    for (int i = 1; i <= m; i++) {
        if (!marked[i]) {
            u.merge(edge[i].first, edge[i].second);
        }
    }

    vector<int> ans;
    for (int i = q - 1; i >= 0; i--) {
        if (query[i].first == 1) {
            int x = query[i].second;
            u.merge(edge[x].first, edge[x].second);
        } else {
            ans.push_back(u.cnt);
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
