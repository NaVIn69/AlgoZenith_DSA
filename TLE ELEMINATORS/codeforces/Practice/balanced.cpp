#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    vector<int>prefix(n,0);
    for(int i=0;i<n;i++){
        if(str[i]=='a'){
            prefix[i]=1;
        }else{
            prefix[i]=-1;
        }
        if(i){
            prefix[i]+=prefix[i-1];
        }
        
    }
    // for(int i=0;i<n;i++){
    //     cout<<prefix[i]<<" ";
    // }
    // cout<<endl;
    // equal number of l and r , for each l we have to find out optimal r
    map<int,int>mpp;
    // mpp[prefix[0]]=0;
    for(int i=0;i<n;i++){
        int f=prefix[i];
        if(f==0){
            cout<<1<<" "<<i+1<<endl;
            return ;
        }
        auto it=mpp.find(f);
        if(mpp.find(f)!=mpp.end()){
            cout<<it->second+1<<" "<<i+1<<endl;
            return ;
        }
        mpp[f]=i+1;
    }
    cout<<"-1 -1"<<endl;
    
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}