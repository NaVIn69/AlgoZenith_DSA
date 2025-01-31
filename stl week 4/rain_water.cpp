#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<int,int>mpp;
    map<int,int>mpm;
     char ch='+';
    char ch1='-';
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            if(mpm.count(ch1)){
                mpm[ch1]--;
            }else{
                mpp[s[i]]++;
            }
        }else{
            if(mpp.count(ch)){
                mpp[ch]--;
            }else{
                mpm[s[i]]++;
            }

        }
    }
   // char ch='+';
    //char ch1='-';
    int ans=abs(mpp[ch]+mpm[ch1]);
    cout<<ans<<endl;

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