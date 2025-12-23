#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long
void solve(){
    int n;
    cin>>n;
     vector<pair<int,pair<int,int>>>v;
    while(n--){
        int x,y;
        cin>>x>>y;
        int d=x*x+y*y;
        pair<int,int>p={x,y};
         pair<int,pair<int,int>>p2={d,p};
         v.push_back(p2);

    }
    int k;
    cin>>k;
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<k;i++){
        pair<int,int> p= v[i].second;
        cout<<p.first<<" "<<p.second<<endl;
        
    }
     
 


}
signed main(){
    solve();
} 