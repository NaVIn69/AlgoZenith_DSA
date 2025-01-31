#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    vector<int>v;
    while(q--){
        int t,x;
        cin>>t>>x;

        if(t==1){
            auto it=lower_bound(a,a+n,x);
            if(it!=(a+n)){
                v.push_back(*it);

            }else{
                v.push_back(-1);
            }

        }else if(t==2){
            auto it=upper_bound(a,a+n,x);
            if(it!=(a+n)){
                v.push_back(*it);
            }else{
                v.push_back(-1);
            }
        }else if(t==3){
            v.push_back(upper_bound(a,a+n,x)-a);
        }else{
            v.push_back(lower_bound(a,a+n,x)-a);
        }
    }
    for(int i=0;i<v.size();i++){
        i!=v.size()-1 ? cout<<v[i]<<" ":cout<<v[i]<<endl;
    }

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}