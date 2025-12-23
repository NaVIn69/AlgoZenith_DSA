#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, c;
int arr[100];

void solve() {
    cin >> n >> c;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    if (n == 1) {
        cout << (arr[0] > c ? 1 : 0) << endl;
        return;
    }

    while (true) {
        auto it = st.upper_bound(c);
        
        // Move to largest element <= c
        if (it == st.begin()) {
            // All elements are > c
            break;
        }
        --it; // Now *it <= c

        // Remove the largest value ≤ c
        st.erase(it);

        // Double the rest
        multiset<int> temp;
        for (int val : st) {
            temp.insert(val * 2);
        }
        st = temp;

        if (st.empty()) {
            cout << 0 << endl;
            return;
        }
    }

    cout << st.size() << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
