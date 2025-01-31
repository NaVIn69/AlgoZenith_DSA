#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    // left me konse index pe same character mila uske liye vector
    //jo map me first time mil rha hai uske liye 0
    vector<int>v(n,0);
    map<int,int>mpp;
    for(int i=0;i<n;i++){
       if(mpp.find(s[i])==mpp.end()){
        mpp[s[i]]=i;
        v[i]=0;
       }else{
        v[i]=mpp[s[i]];
        mpp[s[i]]=i;
       }
    }
    int cnt=0;
    map<int,int>mpp2;
    for(int i=0;i<n;i++){
         if(mpp2.find(s[i])==mpp2.end()){
            cnt+=((n-i)+(i-v[i])*(n-i));
         }else{
            cnt+=((n-i)+(i-v[i]-1)*(n-i));
         }
         mpp2[s[i]]++;
    }
    cout<<cnt<<endl;

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