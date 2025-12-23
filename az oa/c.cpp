#include <bits/stdc++.h>
using namespace std;

//search[n];
//time[n];
int n,k;
int time1[100100];
int search1[100100];
int dp[200010];
int func(int index){
    if(index>n)return 0;
    if(index==n){
        return 0;
    }
    if(dp[index]!=-1)return dp[index];
    int ans=1e9;
    ans=min(ans,time1[index]+func(index+1));
    for(int i=1;i<=k;i++){
        int nextInd=index+i;
        ans=min(ans,search1[index]+func(nextInd));
    }
    return dp[index]=ans;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>time1[i];
    }
    for(int i=0;i<n;i++){
        cin>>search1[i];
    }
    cin>>k;
    memset(dp,-1,sizeof(dp));
   cout<<func(0)<<endl;
    
}