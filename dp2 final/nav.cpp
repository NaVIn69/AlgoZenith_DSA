#include<bits/stdc++.h>
using namespace std;
int dp[101][10001];

int kanpsack(int arr[],int n,int i,int sum_left){
     if(sum_left<0) return 0;
    if(i==n){
        if(sum_left==0){
            return 1;
        }
        return 0;
     }
    if(dp[i][sum_left]!=-1){
        return dp[i][sum_left];
    }
    int ans=kanpsack(arr,n,i+1,sum_left)|kanpsack(arr,n,i+1,sum_left-arr[i]);
     return dp[i][sum_left]=ans;
}
int ArrayAddition(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);

    }
    for(int i=0;i<n;i++){
        if(arr[i]==maxi){
            arr[i]=0;
        }
    }
    if(maxi<=0){
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    if(kanpsack(arr,n,0,maxi)){
        return true;
    }
    return false;

}
int main(){
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 
}