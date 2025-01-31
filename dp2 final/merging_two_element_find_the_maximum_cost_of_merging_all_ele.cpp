#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[500];
int dp[505][505];
// for generating the solution how we merge the element to get maximum cost
// we use the back array
int back[505][505];

int rec(int l,int r){
    // 
    if(l==r){
        return 0;
        // here we can not merge the single ele
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=0;
    int tot=0;
    int sum=0;
    for(int i=l;i<=r;i++){
        tot+=arr[i];
    }
    // here we are traversing all the  possible mid value 
    for(int mid=l;mid<r;mid++){
        sum+=arr[mid];
        // here for every l to r we storing the optimal mid value
        if(rec(l,mid)+rec(mid+1,r)+((sum%100)*(tot-sum)%100)>ans){
            ans=rec(l,mid)+rec(mid+1,r)+((sum%100)*(tot-sum)%100);
            back[l][r]=mid;
        }
    }
    return dp[l][r]=ans;

}
int opb[505];
// this represent the opening bracket and tells me which element have to merge 
int clb[505];
// this respresent the closing bracket  of every opeing bracket
void generate(int l,int r){
    if(l==r){
        return ;
    }
    opb[l]++;
    clb[r]++;
    int mid=back[l][r];
    generate(l,mid);
    generate(mid+1,r);

}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
    generate(0,n-1);

    // here we have been print the solution ,how we find the maximum sum
    for(int i=0;i<n;i++){
        for(int j=0;j<opb[i];j++){
            cout<<"(";
        }
        cout<<" "<<arr[i]<<" ";
        for(int j=0;j<clb[i];j++){
            cout<<")";
        }
    }

}
signed main(){
    solve();
}