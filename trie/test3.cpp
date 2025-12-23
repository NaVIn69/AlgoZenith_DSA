#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

struct Group {
    int value;
    int count;
};

int dp[100][100][100]; // dp[i][j][k] => max score from i to j with k same boxes as group[i]

// Recursive DP
int solve(vector<Group>& groups, int l, int r, int k) {
    if (l > r) return 0;
    if (dp[l][r][k] != -1) return dp[l][r][k];

    // Case 1: remove group[l] along with k more same-value groups stacked before it
    int res = (groups[l].count + k) * (groups[l].count + k) + solve(groups, l + 1, r, 0);

    // Case 2: merge later groups with same value
    for (int m = l + 1; m <= r; ++m) {
        if (groups[m].value == groups[l].value) {
            res = max(res, solve(groups, l + 1, m - 1, 0) + solve(groups, m, r, k + groups[l].count));
        }
    }

    return dp[l][r][k] = res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    // Compress into group[value, count]
    vector<Group> groups;
    for (int i = 0; i < n;) {
        int val = arr[i], cnt = 0;
        while (i < n && arr[i] == val) cnt++, i++;
        groups.push_back({val, cnt});
    }

    memset(dp, -1, sizeof(dp));
    int result = solve(groups, 0, groups.size() - 1, 0);
    cout << result << endl;
    return 0;
}
