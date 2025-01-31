#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int weight[3000];
int val[3000];
int dp[3000][3000];
// here we have generate the solution for which what is the maximum value i can obtain by selecting the element whose sum is equal to less than w
vector<int>solution;

int rec(int level,int wleft){
    // this fn give me the maximum value we can obtain by wleft in the level........n

    //base case
    if(level==n){
        // here we have been traverse all the element
        return 0;
    }
    // cache
    if(dp[level][wleft]!=-1){
        return dp[level][wleft];
    }
    // transition
    // choice
    // dont take
    int ans=rec(level+1,wleft);
    // take
    if(wleft>=weight[level]){
        ans=max(ans,val[level]+rec(level+1,wleft-weight[level]));
    }
    return dp[level][wleft]=ans;
}
void generate(int level,int wleft){ 
     
     // 
     if(level==n){
        return ;
     }else{
        // choice 
        // dont take
        int donttake=rec(level+1,wleft);

        // take
      int take=0;
        if(wleft>=weight[level]){
      take=rec(level+1,wleft-weight[level]);
        }
         if(donttake>take){
         // then we cant take that element
         generate(level+1,wleft);
        }else{
            // meas we taking that element
            solution.push_back(level);
            generate(level+1,wleft-weight[level]);
        }
     }
}
void solve(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    memset(dp,-1,sizeof(dp));
   int maxi=rec(0,w);
   cout<<maxi<<endl;
   generate(0,w);
   for(auto v:solution){
    cout<<v<<" ";
   }
   cout<<endl;

}
signed main(){
    solve();
}