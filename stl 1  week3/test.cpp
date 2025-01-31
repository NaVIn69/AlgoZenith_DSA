#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve1(){
    int n,x;
    cin>>n>>x;
    int a[n];
    int p[n+1];
    p[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        
        
    }
    // this the first way to print the index of that subarray whoes sum is equal to x
    // by making the prefix sum with n+1 size;
    /*
    cout<<endl;
    /// here we made the prefix sum with n+1 size and starting value we have been keep the 0
    cout<<p[0]<<" ";
   for(int i=1;i<=n;i++){
    p[i]=p[i-1]+a[i-1];
    cout<<p[i]<<" ";
   }
   cout<<endl;
   // here we have to find the index of that subarry which sum is x
   map<int,vector<int>>mpp;
   for(int i=0;i<=n;i++){
    int find =p[i]-x;
    for(auto v:mpp[p[i]-x]){
        // here we have increse the index of prefix array by i here v  is l  
        // i-1 is r
        cout<<v<<" ,"<<i-1<<endl;
    }
    mpp[p[i]].push_back(i);

      
   }*/
   

  // 2nd method without incrase the size of prefix sum

   // here we make 
   // prefix sum
   for(int i=0;i<n;i++){
    if(i) a[i]+=a[i-1];
   }
   map<int,vector<int>>mpp;
   mpp[0].push_back(-1);
   for(int i=0;i<n;i++){
    // print the index when we find any l for our R
    for(auto v:mpp[a[i]-x]){
        cout<<v+1<<","<<i<<endl;
    }
    mpp[a[i]].push_back(i);

   }
   

}
signed main(){
    int t=1;
    while(t--){
        solve();
    }
}
/*

#define F first
#define S second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
 
const int MOD=1e9+7;
const int N=1e5+5;
const int maxN = 2e5;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
*/