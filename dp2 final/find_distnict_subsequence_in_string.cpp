#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    string s;
    cin>>s;
    n=s.size();

    int dp[n+1];
    // dp[i] tells me about the number of distnict subsequence upto index i
    int last_index[26]={-1};
    // here in last array we store the last index of every character
    int prefix[n+1];
    // in prefix[i] tells me total subsequence formed upto index i
    memset(last_index,-1,sizeof(last_index));
     dp[0]=1;
     prefix[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=prefix[i-1];
        // checking the last index
        if(last_index[s[i-1]-'a']!=-1){
             int idx=last_index[s[i-1]-'a'];
            dp[i]-=prefix[idx];
        }
        last_index[s[i-1]-'a']=i-1;
        prefix[i]=prefix[i-1]+dp[i];
    }
    cout<<prefix[n]-1<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}