#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> fee; 

// Encode edge uniquely (min,max)
long long encode(int u, int v) {
    if (u > v) swap(u, v);
    return ((long long)u << 32) | v;
}

// Add fee to path between a and b
void addFee(int a, int b, long long x) {
    while (a != b) {
        if (a > b) {
            long long key = encode(a, a/2);
            fee[key] += x;
            a /= 2;
        } else {
            long long key = encode(b, b/2);
            fee[key] += x;
            b /= 2;
        }
    }
}

// Get total cost from a to b
long long getCost(int a, int b) {
    long long total = 0;
    while (a != b) {
        if (a > b) {
            long long key = encode(a, a/2);
            total += fee[key];
            a /= 2;
        } else {
            long long key = encode(b, b/2);
            total += fee[key];
            b /= 2;
        }
    }
    return total;
}

int solve(int q, vector<vector<long long>> &events) {
    long long result = 0;
    for (auto &e : events) {
        if (e[0] == 1) { // fee update
            addFee(e[1], e[2], e[3]);
        } else { // data transfer
            result += getCost(e[1], e[2]);
        }
    }
    return (int)result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int q;
    cin >> q;
    vector<vector<long long>> events(q, vector<long long>(4));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> events[i][j];
        }
    }

    cout << solve(q, events) << "\n";
    return 0;
}
