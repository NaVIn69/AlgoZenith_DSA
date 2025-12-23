#include<bits/stdc++.h>
using namespace std;
bool isStrictlyIncreasing(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] <= arr[i - 1]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> years(n);
    for (int i = 0; i < n; ++i)  cin >> years[i];


    int count = 0;

   
    for (int i = 0; i < n; ++i) {          
        for (int j = i; j < n; ++j) {      
            vector<int> remaining;

           
            for (int k = 0; k < n; ++k) {
                if (k < i || k > j) {
                    remaining.push_back(years[k]);
                }
            }

            if (!remaining.empty() && isStrictlyIncreasing(remaining)) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
