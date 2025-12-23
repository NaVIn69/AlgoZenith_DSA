#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> adj;

// BFS to find shortest path from source to all nodes
vector<int> bfs(int src, int n) {
    vector<int> dist(n + 1, INF);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int tree_nodes = 4;
    vector<int> tree_from = {1, 2, 2};
    vector<int> tree_to = {3, 3, 4};
    int start_node = 1, end_node = 2;
    vector<int> task_nodes = {4};

    // 1. Build graph
    adj.assign(tree_nodes + 1, {});
    for (int i = 0; i < tree_from.size(); ++i) {
        adj[tree_from[i]].push_back(tree_to[i]);
        adj[tree_to[i]].push_back(tree_from[i]);
    }

    // 2. Prepare list of special nodes: start + tasks + end
    vector<int> special = task_nodes;
    special.insert(special.begin(), start_node);
    special.push_back(end_node);

    int k = special.size();
    vector<vector<int>> dist(k, vector<int>(k));

    // 3. Build dist matrix between all special nodes
    for (int i = 0; i < k; ++i) {
        vector<int> d = bfs(special[i], tree_nodes);
        for (int j = 0; j < k; ++j) {
            dist[i][j] = d[special[j]];
        }
    }

    // 4. TSP DP: dp[mask][i] = min cost to reach node i with mask visited
    int taskCount = task_nodes.size();
    int ALL = (1 << taskCount);
    vector<vector<int>> dp(ALL, vector<int>(k, INF));

    dp[0][0] = 0; // Start at special[0] with no tasks done

    for (int mask = 0; mask < ALL; ++mask) {
        for (int u = 0; u < k; ++u) {
            if (dp[mask][u] == INF) continue;
            for (int t = 0; t < taskCount; ++t) {
                if (!(mask & (1 << t))) {
                    int v = t + 1; // task_nodes start at index 1 in special
                    int new_mask = mask | (1 << t);
                    dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }
    }

    // 5. Add distance to end_node (last in special)
    int res = INF;
    for (int i = 1; i <= taskCount; ++i) {
        res = min(res, dp[ALL - 1][i] + dist[i][k - 1]);
    }

    cout << "Minimum time required: " << res << endl;
    return 0;
}
