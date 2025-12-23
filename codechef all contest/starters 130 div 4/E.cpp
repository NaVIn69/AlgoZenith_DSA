#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
     vector<int>ans;
     //here we break our string into smallest even length(2) and we compare the s[i] and s[i+1] if they not equal
     // we are compare with previous char index which has been swap
     for(int i=0;i<n;i+=2){
        if(s[i]!=s[i+1]){
            // ans.size==0 means we flipping the first time
            // s[ans.back()]==s[i+1]   means    we are comapring which previously which index we have been flipping
            if(ans.size()==0 ||s[ans.back()]==s[i+1]){
                ans.push_back(i);
            }else{
                ans.push_back(i+1);
            }
        }
     }
     cout<<ans.size()<<endl;
     for(auto v:ans){
        cout<<v+1<<" ";
     }
     cout<<endl;

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