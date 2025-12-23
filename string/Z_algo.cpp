#include<bits/stdc++.h>
using namespace std;

vector<int> calculateZ(string s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            Z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                Z[i] = R-L; R--;
            }
        }
    }
    return Z;
}


int main() {
    string text = "aaaaaa";
    vector<int> Z = z_function(text);
    // it used to find the pattern matching 
    // s=pattern+@+text apply the z algo on that string s then we can find the pattern in text 
    // verynice construction s=pattern+@+text

    cout << "The Z-array is: ";
    for (int i = 0; i < Z.size(); i++) {
        cout << Z[i] << " ";
    }
    cout << endl;

    return 0;
}