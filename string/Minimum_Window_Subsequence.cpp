#include<bits/stdc++.h>
using namespace std;

string minWindow(string S, string T) {
    int n = S.size(), m = T.size();
    int min_len = INT_MAX;
    int start_idx = -1;

    for (int i = 0; i < n; i++) {
		// from every start we are trying to findout the subsequence
        if (S[i] == T[0]) {
            int s_ptr = i;
            int t_ptr = 0;
			

            while (s_ptr < n && t_ptr < m) {
                if (S[s_ptr] == T[t_ptr]) {
                    t_ptr++;
                }
                s_ptr++;
            }

            if (t_ptr == m) {
                // Backtrack to minimize window
                int end = s_ptr - 1;
                t_ptr = m - 1;
                while (t_ptr >= 0) {
                    if (S[s_ptr - 1] == T[t_ptr]) {
                        t_ptr--;
                    }
                    s_ptr--;
                }

                int window_start = s_ptr;
                if (end - window_start + 1 < min_len) {
                    min_len = end - window_start + 1;
                    start_idx = window_start;
                }
            }
        }
    }

    return start_idx == -1 ? "" : S.substr(start_idx, min_len);
}


void solve(){

}
int main(){
    solve();
}