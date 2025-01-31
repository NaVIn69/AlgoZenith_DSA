#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<int>v(n+1),prefix(n+2,0),frq(n);
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }
  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    prefix[l]++;
    prefix[r+1]--;
  }
  // making frequency array
  vector<pair<int,int>>v1;
  for(int i=1;i<=n;i++){
     prefix[i]+=prefix[i-1];
   v1.push_back({v[i],prefix[i]});
  }
  sort(v1.begin(),v1.end());
  for(int i=0;i<n;i++){
    if(i==0){
      frq[i]=v1[i].second;

    }else{
       frq[i]=frq[i-1]+v1[i].second;
    }
  }
  for(int i=0;i<q;i++){
    int k;
    cin>>k;
    if(lower_bound(frq.begin(),frq.end(),k)!=frq.end()){
          int x=lower_bound(frq.begin(),frq.end(),k)-frq.begin();
          cout<<v1[x].first<<" ";
    }else{
      cout<<"-1"<<" ";
    }
  }
  cout<<endl;

}
signed main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}