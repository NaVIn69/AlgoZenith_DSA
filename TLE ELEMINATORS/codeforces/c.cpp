#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
       int s[n],t[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }  
       map<int,int>ss,tt;
        
        for (int x : s) {
            int r = x % k;
            int g;
            if (r == 0 || (k % 2 == 0 && r == k/2)) {
                g = r;  
            } else {
                g = min(r, k - r); 
            }
            ss[g]++;
        }
        
        for (int x : t) {
            int r = x % k;
            int g;
            if (r == 0 || (k % 2 == 0 && r == k/2)) {
                g = r;  
            } else {
                g = min(r, k - r);  
            }
            tt[g]++;
        }
        
        bool pos = true;
        for (auto& p : tt) {
            if (ss[p.first] < p.second) {
                pos = false;
                break;
            }
        }
        
        cout << (pos ? "YES" : "NO") <<endl;
    }
    

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}