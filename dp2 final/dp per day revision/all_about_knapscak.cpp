#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,target;
int arr[105];
int dp[101][10010];


// 0-1 kanpscak
//here we cant take neighbour element
 
int rec(int level,int left){
    // here this return the (true/false) ,can we form the left from  (level ...... n-1)

    if(level>=n){

        if(left==0){
            return 1;
        }
        return 0;
    }
    if(dp[level][left]!=-1){
        return dp[level][left];
    }
    // choice
   // dont take
    int ans=rec(level+1,left);
    // take
    if(left>=arr[level]){
        /*
        // 0-inf knapscak
        // ans=ans|rec(level,left-arr[level]);
        */
        ans=ans|rec(level+2,left-arr[level]);
    }

return dp[level][left]=ans;
   

}
// here we have to print the solution
// rec give me 0/1
void generate(int level,int left){
    if(level>=n){
        return ;
    }else{
        int donttake=rec(level+1,left);
        int take=0;
        if(left>=arr[level]){
            take=rec(level+2,left-arr[level]);
        }
       if(take>donttake){
         cout<<arr[level]<<" ";
         generate(level+2,left-arr[level]);
       }else{
        generate(level+1,left);

       }

    }
}


// int rec2(int level,int left){
//     // this will give the totalnumber of ways to form the left from (level to n-1);
//     if(left<0) return 0;
//     if(level==n){
//         if(left==0){
//             // cout<<level<<endl;
//             return 1;
//         }
//     }
//     if(left==0){
//         // cout<<level<<endl;
//         return 1;
//     }
//     if(dp[level][left]!=-1){
//        return dp[level][left];
//     }

//     // transition
//     int ans=0;
//     ans+=rec2(level+1,left);
//     if(left>=arr[level]){
//         ans+=rec2(level+1,left-arr[level]);
//     }
//   return   dp[level][left]=ans;


// }

void solve(){
    cin>>n>>target;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,target)<<endl;
    generate(0,target);
    // for(int i=0;i<n;i++){
    //     for(int left=0;left<=target;left++){
    //         cout<<dp[i][left]<<" ";
    //     } 
    //     cout<<endl;
    // }

    
}
signed main(){
    solve();
}