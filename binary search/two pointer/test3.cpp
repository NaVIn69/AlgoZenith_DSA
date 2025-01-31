#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(n) int n; cin>>n;
#define readstr(s) string s; cin>>s;
using namespace std;
void solve(){
    readstr(s);
    int n=s.size();
    // take two pointer;
    int head=-1,tail=0;
    // data structure to maintain
    map<char ,int>mpp;
    // ans to store 
    int ans=0;
    while(tail<n){
        // eat as many as possible element
        while(head+1<n && (mpp[s[head+1]]<2)){
           mpp[s[head+1]]++;
           head++;
        }
        // store the answer for that tail
        int len=head-tail+1;
        ans=max(len,ans);
       // cout<<ans<<" "<<head<<" "<<tail<<" "<<endl;
        // move forward the tail
        if(tail<=head){
            mpp[s[tail]]--;
             if(mpp[s[tail]]==0) mpp.erase(s[tail]);
            tail++;
        }else{
            tail++;
  
            head=tail-1;
        }

    }
    cout<<ans<<'\n';

}
signed main(){
    IOS
    solve();
}