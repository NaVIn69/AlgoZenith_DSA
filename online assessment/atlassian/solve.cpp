#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        if (n <= 2) {
            return 0; // Cannot form a path with 2 or fewer nodes
        }

        vector<set<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        // --- Stage 1: Prune leaves without coins ---
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1 && coins[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (adj[u].empty()) continue; // Should not happen in a connected tree
            
            int v = *adj[u].begin(); // The only neighbor
            
            adj[u].erase(v);
            adj[v].erase(u);

            if (adj[v].size() == 1 && coins[v] == 0) {
                q.push(v);
            }
        }
        
        // --- Stage 2 & 3: Prune two layers of leaves ---
        for (int i = 0; i < 2; ++i) {
            queue<int> leaves_to_prune;
            for(int j = 0; j < n; ++j) {
                if (adj[j].size() == 1) {
                    leaves_to_prune.push(j);
                }
            }
            if (leaves_to_prune.empty()) break; // No more leaves to prune

            while(!leaves_to_prune.empty()) {
                int leaf = leaves_to_prune.front();
                leaves_to_prune.pop();
                
                if (adj[leaf].empty()) continue;
                
                int neighbor = *adj[leaf].begin();
                adj[leaf].erase(neighbor);
                adj[neighbor].erase(leaf);
            }
        }
        
        // --- Final Calculation ---
        int remaining_edges = 0;
        for (int i = 0; i < n; ++i) {
            remaining_edges += adj[i].size();
        }
        
        // Each edge is counted twice (once for each endpoint), so divide by 2
        return remaining_edges;
    }
};

int main() {
    Solution sol;

    // Example from the image
    int treenode;
    cin>>treenode;
    vector<int>tree_from,tree_to,coin;
    tree_from.resize(treenode+1);
    tree_to.resize(treenode+1);
    coin.resize(treenode+1);
    
   for(int i=0;i<treenode;i++){
       cin>>tree_from[i];
   }
   for(int i=0;i<treenode;i++){
       cin>>tree_to[i];
   }
    for(int i=0;i<treenode;i++){
       cin>>coin[i];}
    vector<int> coins;
    for(int i=0;i<treenode;i++){
       coins.push_back(coin[i]);
    }
    vector<vector<int>> edges;
    for(int i=0;i<treenode;i++){
       edges.push_back({tree_from[i],tree_to[i]});
    }
    cout << sol.collectTheCoins(coins, edges) << endl;
   }
    