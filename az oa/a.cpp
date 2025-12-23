#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
    int solve(int eggs, int floors) {
        // Base cases
        if (floors == 0 || floors == 1)
            return floors;
        if (eggs == 1)
            return floors;

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int ans = INT_MAX;

        for (int k = 1; k <= floors; k++) {
            int broken = solve(eggs - 1, k - 1);
            int notBroken = solve(eggs, floors - k);

            int worst = 1 + max(broken, notBroken);
            ans = min(ans, worst);
        }

        return dp[eggs][floors] = ans;
    }

    int superEggDrop(int eggs, int floors) {
        dp.assign(eggs + 1, vector<int>(floors + 1, -1));
        return solve(eggs, floors);
    }
    int main(){
        int n,f;
        cin>>n>>f;
        cout<<superEggDrop(n,f)<<endl;
        return 0;
    }
