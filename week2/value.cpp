#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<int>arr(n+1),prefix(n+2,0),dq(n);
  // for solving on first based index we take the input from first index(1st index)
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  while(m--){
    int l,r;
    cin>>l>>r;
    prefix[l]++;
    prefix[r+1]--;
  }
  
  // that prefix array is frequency array
  // copy in the frequency of array and element of array
  vector<pair<int,int>>v;
  for(int i=1;i<=n;i++){
    //here at index 0 pe 0 hai in prefix array
    if(i!=0){
    prefix[i]+=prefix[i-1];
    v.push_back({arr[i],prefix[i]});
    }
  }
  
  sort(v.begin(),v.end());
  // here we are making the prefix function of frequency
  vector<int>v1;
  for(int i=0;i<n;i++){
    if(i==0){
        dq[i]=v[i].second;
    }else{
        dq[i]=dq[i-1]+v[i].second;
    }
      
  }
 
  for(int i=0;i<q;i++){

  int k;
  cin>>k;
   
   
    if(lower_bound(v1.begin(),v1.end(),k)!=v1.end()){
      int x=lower_bound(v1.begin(),v1.end(),k)-v1.begin();
      cout<<v[x].first<<" ";

    }else{
      cout<<"-1"<<" ";
    }
  }
  cout<<endl;
}
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}