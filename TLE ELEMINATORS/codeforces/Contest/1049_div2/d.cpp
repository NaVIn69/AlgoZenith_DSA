#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
   int n;
   cin>>n;
   vector<int>l(n),r(n);
   int sum=0;
   for(int i=0;i<n;i++){
     cin>>l[i]>>r[i];
     sum+=(r[i]-l[i]);
   }
   int ex=0;
   sort(l.begin(),l.end());
   sort(r.rbegin(),r.rend());
   for(int i=0;i<n/2;i++){
      int d=r[i]-l[i];
      ex+=d;
   }
   cout<<sum+ex<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}