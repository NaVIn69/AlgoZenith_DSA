#include <bits/stdc++.h>
using namespace std;

// BFS function to find the farthest node from start and reconstruct the path
pair<int, vector<int>> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    int farthest = start;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[farthest]) farthest = i;
    }
    // reconstruct path
    vector<int> path;
    for (int cur = farthest; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    return {farthest, path};
}

int solve_case(int n, vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e.first - 1].push_back(e.second - 1);
        adj[e.second - 1].push_back(e.first - 1);
    }
    
    // Step 1: Find one endpoint of diameter
    pair<int, vector<int>> p1 = bfs(0, adj);
    int endpoint1 = p1.first;
    
    // Step 2: Find the other endpoint and get diameter path
    pair<int, vector<int>> p2 = bfs(endpoint1, adj);
    int endpoint2 = p2.first;
    vector<int> diameter_path = p2.second;
    
    int diameter_length = diameter_path.size() - 1; // diameter length in edges
    
    // Step 3: Calculate minimum operations needed
    // The operation collapses a path into a star
    // We need to find the minimum number of operations to achieve minimum diameter
    
    // For n=2: minimum diameter is 1
    // For n≥3: minimum diameter is 2 (star graph)
    
    if (n == 2) {
        return (diameter_length > 1) ? 1 : 0;
    }
    
    // For n ≥ 3, we need to reduce diameter to 2
    // The operation is more complex than just halving
    // We need to simulate the actual effect of operations
    
    // Let's calculate the minimum number of operations needed
    // Each operation can reduce the diameter, but not necessarily by half
    
    int ops = 0;
    int current_diameter = diameter_length;
    
    // We need to reduce diameter to 2
    // The operation effect depends on the structure
    // Let's try a different approach - calculate the minimum number of operations needed
    
    // For a tree with diameter d, we need to find the minimum number of operations
    // to reduce it to 2
    
    // Let's try a more careful calculation

    
    // Each operation can reduce the diameter
    // But the exact reduction depends on the tree structure
    // Let's try a different formula
    while (current_diameter > 2) {
        // For complex trees, the reduction might be less than half
        current_diameter = max(2, (current_diameter + 1) / 2);
        ops++;
    }
    
    return ops;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> edges[i].first >> edges[i].second;
        }
        cout << solve_case(n, edges) << "\n";
    }
    return 0;
}
