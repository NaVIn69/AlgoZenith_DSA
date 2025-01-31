#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> arrA(n), arrB(n);

    map<int, int> mppa, mppb;

  
    for (int i = 0; i < n; i++) {
    
        mppa[arrA[i]]++;
    }
    for (int i = 0; i < n; i++) {
    
        mppb[arrB[i]]++;
    }

    
    multiset<int> surplusA, surplusB;
 
    for (auto &v : mppa) {
        int cntA = v.second;
        int cntB = mppb[v.first]; 
        
        if ((cntA + cntB) % 2 != 0) {
            cout << "-1" << endl;
            return;
        }

        int diff = cntA - cntB;
        if (diff > 0) {
            // Surplus in A
            for (int i = 0; i < diff / 2; i++) {
                surplusA.insert(v.first);
            }
        } else if (diff < 0) {
            // Surplus in B (deficit in A)
            for (int i = 0; i < (-diff) / 2; i++) {
                surplusB.insert(v.first);
            }
        }
    }

    // Now handle elements in B that are extra and not balanced by A
    for (auto &v : mppb) {
        int cntB = v.second;
        int cntA = mppa[v.first];  // Get count of the same element in A
        
        int diff = cntB - cntA;
        if (diff > 0) {
            // Surplus in B
            for (int i = 0; i < diff / 2; i++) {
                surplusB.insert(v.first);
            }
        }
    }

    // Now we have two sets: surplusA and surplusB. These need to be swapped
    if (surplusA.size() != surplusB.size()) {
        cout << "-1" << endl;
        return;
    }

    // Minimize cost: Try to swap the smallest values from both sets
    int cost = 0;
    auto itA = surplusA.begin();
    auto itB = surplusB.begin();

    while (itA != surplusA.end() && itB != surplusB.end()) {
        cost += min(*itA, *itB);
        itA++;
        itB++;
    }

    cout << cost << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
