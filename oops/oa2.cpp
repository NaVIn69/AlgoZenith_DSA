#include <bits/stdc++.h>
using namespace std;

vector<int> isCompliant(int N, vector<vector<int>> &Arr) {
    vector<int> parent(N+1), comp(N+1), removed(N+1, 0);
    vector<vector<int>> children(N+1);

    for (int i = 1; i <= N; ++i) {
        parent[i] = Arr[i-1][0];
        comp[i]   = Arr[i-1][1];
        if (parent[i] != -1) children[parent[i]].push_back(i);
    }

    // compliantChildrenCount[i] = number of direct children of i that are compliant (C == 0)
    vector<int> compliantChildrenCount(N+1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int v : children[i]) {
            if (comp[v] == 0) compliantChildrenCount[i]++;
        }
    }

    // min-heap of candidate IDs (non-compliant and have no compliant direct children)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; ++i) {
        if (comp[i] == 1 && compliantChildrenCount[i] == 0) pq.push(i);
    }

    vector<int> result;
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();

        // validate current state (skip if already removed or no longer valid)
        if (removed[u]) continue;
        if (!(comp[u] == 1 && compliantChildrenCount[u] == 0)) continue;

        // remove u
        removed[u] = 1;
        result.push_back(u);

        int p = parent[u];

        // reassign every current child v of u to p
        // note: children[u] might contain nodes whose parent changed earlier; only process those still with parent==u
        for (int v : children[u]) {
            if (parent[v] != u) continue; // skip stale entry
            parent[v] = p;               // reassign

            if (p != -1) {
                children[p].push_back(v);          // add to parent's child list
                if (!removed[v] && comp[v] == 0)  // if v is compliant, parent's compliant count increases
                    compliantChildrenCount[p]++;
            }
        }
        // clear u's children list (optional but avoids reprocessing later)
        children[u].clear();

        // parent might become candidate now (or might have become invalid). push to pq for re-check.
        if (p != -1 && !removed[p] && comp[p] == 1 && compliantChildrenCount[p] == 0) {
            pq.push(p);
        }
    }

    if (result.empty()) return vector<int>{-1};
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<vector<int>> Arr(N, vector<int>(2));
    for (int i = 0; i < N; i++) cin >> Arr[i][0] >> Arr[i][1];

    vector<int> ans = isCompliant(N, Arr);
    if (ans.size() == 1 && ans[0] == -1) {
        cout << -1 << '\n';
    } else {
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
