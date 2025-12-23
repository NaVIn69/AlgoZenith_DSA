#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    // first find all divisor
    if(k>=n){
      cout<<1<<endl;
      return ;
    }
    vector<int>div;
    
    for(int i=1;i*i<=n;i++){
       if(n%i==0){
         div.push_back(i);
          if(i*i!=n){
            div.push_back(n/i);
          }
       }
    }
    sort(div.begin(),div.end());
    // for(int x:div){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    int idx=lower_bound(div.begin(),div.end(),k)-div.begin();
    // cout<<idx<<endl;
    // cout<<div[idx]<<endl;
    if(div[idx]>k){
        idx--;
       cout<<(n/div[idx])<<endl;
    }else{
        cout<<(n/div[idx])<<endl;
    }

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}