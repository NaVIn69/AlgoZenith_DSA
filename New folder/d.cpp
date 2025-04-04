#include <bits/stdc++.h>
using namespace std;

int solve(int N, vector<int> Passengers, vector<vector<int>> Edges) {
    // Create adjacency list representation of the graph
    vector<vector<int>> adj(N + 1);
    for (const auto& edge : Edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    // Count total passengers that need to be transported
    int totalPassengers = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 != 2 && Passengers[i] == 1) { // Skip destination (stop 2)
            totalPassengers++;
        }
    }
    
    if (totalPassengers == 0) return 0;
    
    // Function to check if path exists from start to destination
    auto hasPath = [&](int start, vector<bool>& visited) -> bool {
        if (start == 2) return true;
        visited[start] = true;
        
        for (int next : adj[start]) {
            if (!visited[next]) {
                if (hasPath(next, visited)) {
                    return true;
                }
            }
        }
        return false;
    };
    
    // For each stop with passengers, verify if path exists to destination
    int busesNeeded = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 != 2 && Passengers[i] == 1) { // Skip destination
            vector<bool> visited(N + 1, false);
            if (hasPath(i + 1, visited)) {
                busesNeeded++;
            }
        }
    }
    
    return busesNeeded;
}