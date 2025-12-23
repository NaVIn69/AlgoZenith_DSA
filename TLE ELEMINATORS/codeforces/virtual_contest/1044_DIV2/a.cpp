#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int prod=1;
    map<int,int>mpp;
    bool check=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]++;
        if(mpp[a[i]]>1){
            check=true;
        }
    }
    if(check){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

   
    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}