#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
 set<int>st;
set<int>nst;
int val(int x){

}
void solve(){
    int q,x;
    cin>>q>>x;
   // set<int>st;
   // set<int>nst;
    while(q--){
        int y;
        cin>>y;
        int low=y-x;
        int hi=y+x;
        if(low>=0&&st.find(low)==st.end()){
            st.insert(low);
            nst.erase(low);
            if(!st.count(low+1)){
                nst.insert(low+1);
            }
        }else{
            st.insert(hi);
            nst.erase(hi);
            if(!st.count(hi+1)){
                nst.insert(hi+1);
            }

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