#include <bits/stdc++.h>
using namespace std;

int settle(int start, vector<long long> &balance) {
    while (start < balance.size() && balance[start] == 0) start++;
    if (start == balance.size()) return 0;

    int minTrans = INT_MAX;
    for (int i = start + 1; i < balance.size(); i++) {
        if (balance[start] * balance[i] < 0) {
            balance[i] += balance[start];
            minTrans = min(minTrans, 1 + settle(start + 1, balance));
            balance[i] -= balance[start];
        }
    }
    return (minTrans == INT_MAX) ? 0 : minTrans;
}

int getMinTransactions(int n, vector<vector<int>> &debts) {
    vector<long long> balance(n, 0);
    for (auto &d : debts) {
        balance[d[0]] -= d[2];
        balance[d[1]] += d[2];
    }
    return settle(0, balance);
}

int main() {
    int n, m;
    cin >> n >> m; // number of people, number of debts

    vector<vector<int>> debts(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> debts[i][0] >> debts[i][1] >> debts[i][2];
    }

    cout << getMinTransactions(n, debts) << endl;
    return 0;
}