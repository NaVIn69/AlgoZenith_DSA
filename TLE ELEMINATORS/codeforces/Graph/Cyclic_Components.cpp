#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int node, vector<int>& comp) {
    vis[node] = 1;
    comp.push_back(node);
    for (auto v : g[node]) {
        if (!vis[v]) dfs(v, comp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cycleComponents = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, comp);

            bool isCycle = true;
            for (int v : comp) {
                if (g[v].size() != 2) {
                    isCycle = false;
                    break;
                }
            }
            if (isCycle) cycleComponents++;
        }
    }

    cout << cycleComponents << "\n";
}
