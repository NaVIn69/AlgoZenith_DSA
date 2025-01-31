#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    // taking the set of 26 character to store the index of each character
    vector<set<int>>v(26);
    for(int i=0;s[i]!='\0';i++){
        // i+1 due to one based index
        v[s[i]-'a'].insert(i+1);
    }
    while(q--){
        int n;
        cin>>n;
        if(n==1){
            int i;
            cin>>i;
            char ch;
            cin>>ch;
            // means inserting character c at ith index of string
            v[s[i-1]-'a'].erase(i);
            v[ch-'a'].insert(i);
            s[i-1]=ch;
        }else{
            int l,r;
            cin>>l>>r;
            int cnt=0;
            for(int i=0;i<26;i++){
                // here we are checking the 26 character that how many is lie in between l to r
                char ch='a'+i;
                if(!v[i].empty()){
                auto it=v[i].lower_bound(l);
                if(it!=v[i].end())
                if(*it<=r){
                    cnt++;
                }
                }
            }
            cout<<cnt<<endl;
        }
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