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
    map<char,int>mpp;
    for(int i=0;s[i]!='\0';i++){
        mpp[s[i]]++;
    }
    int mini=min(mpp['0'],mpp['1']);
    if(mini%2){
        cout<<"Zlatan"<<endl;
    }else{
        cout<<"Ramos"<<endl;
    }
    

    

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