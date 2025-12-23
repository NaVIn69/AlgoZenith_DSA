#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool check=false;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cnt++;
            if(cnt>=k){
                check=true;
                break;
            }
        }else{
            cnt=0;
        }
    }
    if(check==true){
        cout<<"NO"<<endl;
        return ;
    }
    vector<int>p(n+1);
    int val=1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            p[i+1]=val;
            val++;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            p[i+1]=val;
            val++;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}