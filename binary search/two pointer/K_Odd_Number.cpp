#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    int a[n];
    int pre[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
      pre[i]=a[i];
      if(i) pre[i]+=pre[i-1];
    }
    // using two pointer to find the optimal r for every l where condition is at most k odd number
    // two pointer
    int head=-1,tail=0;

    // data structure to maintain the window proprety
    int cnt_odd=0;
    multiset<int>mt;

    // store the answer
    int ans=-1e18;
    while(tail<n){
      // eat as many as you can eat
      while(head+1<n && (cnt_odd<k || cnt_odd<=k&&a[head+1]%2==0)){
              if(a[head+1]%2){
                cnt_odd++;
              }
              mt.insert(pre[head+1]);
              head++;
        }
        // here we are finding the optimal r for that l such that p[i]<=d+p[l-1];
        int base=(tail==0?0:pre[tail-1]);
        auto it=mt.upper_bound(base+d);
        if(it!=mt.begin()){
          it--;
          ans=max(ans,*it-base);
        }
      
      // store the answer for that    
      // move the tail one step forward
      if(tail<=head){
        if(a[tail]%2) cnt_odd--;
        mt.erase(mt.find(pre[tail]));
      
      tail++;
      }else{
        tail++;
        head=tail-1;
      }
    }
    if(ans==-1e18){
      cout<<"IMPOSSIBLE"<<endl;
    }else{
      cout<<ans<<endl;
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