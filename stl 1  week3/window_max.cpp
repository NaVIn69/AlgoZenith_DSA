#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

struct monotone_deque_2{
  deque<int>dq;
  void insert(int x){
     while(!dq.empty()&&dq.back()<x){
        dq.pop_back();
     }
     dq.push_back(x);
  }
// erase
void erase(int x){
   if(dq.front()==x){
    dq.pop_front();
   }
}

// getmin value from deque
int getmax(){
  return dq.front();
}

};




  
void solve(){
   int n,k;
   cin>>n>>k;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
    monotone_deque_2 dq;
 vector<int>v;
  for(int i=0;i<k;i++){
    dq.insert(a[i]);
  }
  v.push_back(dq.getmax());

  // for any n-k+1 subbarray
  for(int i=0;i<n-k;i++){
    dq.insert(a[i+k]);
    dq.erase(a[i]);
    v.push_back(dq.getmax());
  }
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
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


  