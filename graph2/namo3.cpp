#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;  // Number of test cases
    
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;  // Number of words
        
        unordered_set<string> seen;
        seen.reserve(n); // Pre-allocate memory to avoid rehashing
        
        bool first = true;
        string word;
        
        // Process each word directly
        for (int i = 0; i < n; ++i) {
            cin >> word;
            
            // If word hasn't been seen before, print it
            if (seen.find(word) == seen.end()) {
                if (!first) {
                    cout << " ";
                } else {
                    first = false;
                }
                cout << word;
                seen.insert(word);
            }
        }
        cout << "\n";
    }
    
    return 0;
}