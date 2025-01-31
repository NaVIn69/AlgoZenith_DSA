#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
string s;
void solve(){
cin>>n;
cin>>s;
map<char,int>mpp;
vector<int>v(n,0);
// right se character konse index 
for(int i=n-1;i>=0;i--){
  if(mpp.find(s[i])==mpp.end()){
    mpp[s[i]]=i;
    v[i]=n;
  }else{
    v[i]=mpp[s[i]];
    mpp[s[i]]=i;
  }
}
// left se character konse index pe hai
vector<int>v2(n,0);
mpp.clear();
for(int i=0;i<n;i++){
    if(mpp.find(s[i])==mpp.end()){
        mpp[s[i]]=i;
        v2[i]=-1;
    }else{
        v2[i]=mpp[s[i]];
        mpp[s[i]]=i;
    }
}


// for every index we are going to find the contribution of each index
int score=0;
for(int i=0;i<n;i++){
    int left=v2[i];
    int right=v[i];
    score+=(right-i)*(i-left);
}
cout<<score<<endl;


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