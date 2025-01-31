#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string str1,str2;
    cin>>str1>>str2;
    map<char,int>mpp;
    for(int i=0;i<str2.size();i++){
        mpp[str2[i]]++;
    }
    int ans=0;
    for(int i=0;i<str1.size();i++){
        if(mpp.find(str1[i])==mpp.end()){
            //remove
            ans++;
        }else if(mpp.find(str1[i])!=mpp.end()){
            mpp[str1[i]]--;
            if(mpp[str1[i]]==0) mpp.erase(str1[i]);
        }
    }
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
