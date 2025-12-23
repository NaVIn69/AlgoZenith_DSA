#include <iostream>
#include <stack>

using namespace std;

// Function to calculate time complexity
string calculateTimeComplexity(string s) {
    stack<char> st;
    int nestedLevel = 0;

    for (int i=0;s[i]!='\0';i++) {
        char c=s[i];
        if (c == 'f') {
            st.push(c);
            nestedLevel++;
            i=i+3;
        } else if (c == 'e') {
            if (!st.empty() && st.top() == 'f') {
                st.pop();
                nestedLevel--;
            } else {
                return "Compile Error";
            }
        }
    }

    if (st.empty()) {
        // Time complexity expression construction
        string result = "n";
        for (int i = 1; i < nestedLevel; i++) {
            result = "n^" + result;
        }

        return result;
    } else {
        return "Compile Error";
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;

        string result = calculateTimeComplexity(s);

        cout << result << endl;
    }

    return 0;
}
