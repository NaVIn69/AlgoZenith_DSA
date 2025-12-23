#include <bits/stdc++.h>
using namespace std;

string numberGame(int input1, string D, string E, string F) {
    // Generate all permutations of F
    sort(F.begin(), F.end());
    string smallest = "-1";
    
    do {
        // Check conditions
        if (F > D && F > E) {
            string revF = F;
            reverse(revF.begin(), revF.end());
            
            string revD = D;
            reverse(revD.begin(), revD.end());
            
            string revE = E;
            reverse(revE.begin(), revE.end());
            
            if (revF < revD && revF < revE) {
                smallest = F;
                break; // since it's the smallest due to sorting
            }
        }
    } while (next_permutation(F.begin(), F.end()));
    
    return smallest;
}

// Example test
int main() {
    cout << numberGame(3, "124", "324", "335") << endl; // Output: 353
    cout << numberGame(2, "12", "23", "32") << endl;    // Output: -1
    return 0;
}
