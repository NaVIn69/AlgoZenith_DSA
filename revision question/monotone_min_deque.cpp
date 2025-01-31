// here we have to find the min element of k window size subarray
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct monotone_min{
   deque<int>dq;
   void insert(int x){
     while(!dq.empty()&&dq.back()>x){
        dq.pop_back();
     }
     dq.push_back(x);
   }
   void delete1(int x){
        if(dq.front()==x){
            dq.pop_front();
        }
   }
   int getmin(){
    return dq.front();
   }
};
void solve(){
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  monotone_min dqmin;
  // first window
  for(int i=0;i<k;i++){
    dqmin.insert(arr[i]);
  }
  cout<<dqmin.getmin()<<endl;
  // remaining window
  for(int i=0;i<n-k;i++){
    dqmin.insert(arr[i+k]);
    dqmin.delete1(arr[i]);
    cout<<dqmin.getmin()<<endl;
  }



}
signed main(){
    solve();
}
