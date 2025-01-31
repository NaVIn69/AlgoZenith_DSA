#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// we have to print all the subsequence whoes sum is equal to k
int n,k;
int arr[100100];
int sum=0;
vector<int>sol;
void rec(int level){
    // here level is the index of array
    if(level==n){
        if(sum==k){
            for(auto v:sol){
                cout<<v<<" ";
            }
            cout<<endl;
        }
        return;

    }
    // choice 
    // take
    
        sum+=arr[level];
        //place
        sol.push_back(arr[level]);
        // move
        rec(level+1);
        // unplace
        sum-=arr[level];
        sol.pop_back();
    
    // dont take
     rec(level+1);
}
void solve(){

    cin>>n>>k;
   // int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rec(0);

}
signed main(){
   solve();
}