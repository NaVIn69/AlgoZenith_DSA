
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1001000];
int count(int i){
    int cnt=0;
    while(i){
        i=i&(i-1);
        cnt++;
    }
    return cnt;
}
int cnt(){
    dp[0]=0;
    for(int i=1;i<=1e5;i++){
        dp[i]=dp[i-1]+count(i);
    }
}
void print(int n){
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}

int countSetBits(int n)
{
    //add code here
    print(n);
  return dp[n];
}


signed  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   cnt();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countSetBits(n) << '\n';
    }

    return 0;
}
