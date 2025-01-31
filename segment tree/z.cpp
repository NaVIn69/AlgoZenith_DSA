#include <iostream>
#include <vector>

using namespace std;

// Function to handle updates
void update(vector<vector<long long>>& P, vector<long long>& delta, int index, long long val, int N) {
    long long old_value = P[index][index];
    long long delta_value = val - old_value;
    
    // Update delta array
    delta[index] += delta_value;
    
    // Apply updates to prefix sum array P
    for (int j = index; j < N; ++j) {
        P[index][j] += delta_value;
    }
}

// Function to handle summation queries
long long double_summation(vector<vector<long long>>& P, vector<long long>& delta, int L, int R) {
    long long total_sum = 0;
    for (int i = L; i <= R; ++i) {
        for (int j = i; j <= R; ++j) {
            total_sum += P[i][j];
        }
    }
    return total_sum;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Initialize array A, prefix sum array P, and delta array
    vector<long long> A(N);
    vector<vector<long long>> P(N, vector<long long>(N, 0));
    vector<long long> delta(N, 0);
    
    // Input array A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        P[i][i] = A[i]; // Initialize diagonal of P
    }
    
    // Process each query
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // Update query: 1 i val
            int i;
            long long val;
            cin >> i >> val;
            i--; // Convert to 0-based index
            update(P, delta, i, val, N);
        } else if (type == 2) {
            // Summation query: 2 L R
            int L, R;
            cin >> L >> R;
            L--; // Convert to 0-based index
            R--; // Convert to 0-based index
            long long result = double_summation(P, delta, L, R);
            cout << result << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}