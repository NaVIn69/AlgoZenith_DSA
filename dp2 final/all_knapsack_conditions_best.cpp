#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int inf=1e9;
// first print_solution
// 0-1 ... 0-inf knapsack problem
// max k items we can take
// sum of k items weight taken should be divisible by m 
// if you take ith element and u cant take (i+1)th element

// here we have n elements and we want to choose k element from n and weight of k elements must be divisible by m 
 int n,k,m,w;
 int weight[101];
 int val[101];
 int dp[101][1001][101];

 int rec(int level,int wleft,int items_taken){
    // here this function return me the the maximum value by choosing the wleft weight of remaing weight and choosing remaing items
    if(level==n){
        int sum_taken=w-wleft;
        if(sum_taken%m==0){
            // valid sum
            return 0;
        }else{
            return -inf;
        }
       
    }

    // choice
    // dont take
    int ans=rec(level+1,wleft,items_taken);
    // taken 
    if(wleft>=weight[level]&&items_taken>0){
        // here we do the level+2 bcz we cant take the neighbour element
        ans=max(ans,rec(level+2,wleft-weight[level],items_taken-1)+val[level]);
    }
    return dp[level][wleft][items_taken]=ans;
 }
void solve(){
    cin>>n>>k>>m>>w;
    int maxi=rec(0,w,k);
    cout<<maxi<<endl;

}
signed main(){
    solve();
}