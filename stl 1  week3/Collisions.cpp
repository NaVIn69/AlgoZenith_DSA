#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool comp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}
int binarysearch(int arr[],int s,int e,int target){
int start=s;
int end=e;
int ans=-1;
while(start<=end){
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
      ans=mid;
      break;
    }else if(target>arr[mid]){
     s=mid+1;
    }else{
        e=mid-1;
    }
}
return ans;
}
void solve(){
int n,m;
cin>>n>>m;
//pair<int,int>a[n];
int a[n];
// first distance then speed
map<int,int>mpp;
for(int i=0;i<n;i++){
    int x,u;
    cin>>x>>u;
   mpp[x*u]++;
}
//pair<int,int>b[m];
int cnt=0;
int b[m];
for(int i=0;i<m;i++){
    int y,v;
    cin>>y>>v;
    if(mpp.count(y*v)){
        cnt++;
        mpp[y*v]--;
        if(mpp[y*v]==0){
            mpp.erase(y*v);
        }
    }
}

     

cout<<cnt<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}