// find the number of distnict subsequence of string
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s;
    cin>>s;
    int n=s.size();

    int prefix[n+1] ;// here we store the sum of dp[0..i]
    int lastt[26]; // here we store the last occurence of that index element
    int dp[n+1];
    //dp[i]  number of distnict subsequence generated using the character ith which is not seen before
    memset(lastt,-1,sizeof(lastt));

    dp[0]=1; // unique subsequence ending at (i-1);
    prefix[0]=1; // sum of dp[0..i]

    for(int i=1;i<=n;i++){
         // add after all charcter
        dp[i]=prefix[i-1];

        if(lastt[s[i-1]-'a']!=-1){
            //remove all duplicate
            int idx=lastt[s[i-1]-'a'];
            // in idx we store the last occurence of that character 
            dp[i]-=prefix[idx];

        }     
        // update the last index where this char is present
        lastt[s[i-1]-'a']=i-1; // i-1 is the real index in that string
        prefix[i]=prefix[i-1]+dp[i];
    }
    //remove the -1 due to dp[0] empty string
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