#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<pair<int,int>>prime_factorisation(int n){
    vector<pair<int,int>>ans;
    for(int i=2;i*i<=n;i++){
      if(n%i==0){
        int cnt=0;
        while(n%i==0){
          cnt++;
          n/=i;
        }
        ans.push_back({i,cnt});
      }
    }
    if(n>1){
      ans.push_back({n,1});
    }
    return ans;
  
  
  }
void solve(){
  int n,k;
  cin>>n>>k;
  if(k==1){
    cout<<n<<endl;
    return ;
  }
  vector<pair<int,int>>prime;
  int x=n;
  int tot=0;
  for(int i=2;i*i<=x;i++){
           if(x%i==0){
               int cnt=0;
               while(x%i==0){
                  cnt++;
                  x/=i;
               }
               tot+=cnt;
               prime.push_back({i,cnt});
           }
  }
  if(x>1){
    tot++;
    prime.push_back({x,1});
  }
//   cout<<tot<<endl;
  
  if(tot<k){
    cout<<"-1"<<endl;
    return ;
  }
  sort(prime.begin(),prime.end());
//   for(auto x:prime){
//     cout<<x.first<<" "<<x.second<<endl;
//   }
 
  int cnt=0;
  int temp=1;
  vector<int>ans; // here we store k-1 factor
  for(int i=0;i<prime.size();i++){
       if(cnt+prime[i].second<=k-1){
       cnt+=prime[i].second;
       int x=prime[i].second;
       while(x--){
         ans.push_back(prime[i].first);
         temp=temp*prime[i].first;
       }
       }else{
          // here we put remainign element
           int rem=k-1-cnt;
           if(cnt==0){
              cnt=k-1;
           }
           while(rem--){
            ans.push_back(prime[i].first);
              temp=temp*prime[i].first;
              
           }


       } 
  }
//   if(cnt==0){
//     cout<<"-1"<<endl;
//     return ;
//   }
  ans.push_back(n/temp);
//   int check=1;
  for(auto x:ans){
    cout<<x<<" ";
    // check*=x;
  }
//   cout<<check<<endl;
  cout<<endl;


}
signed main(){
    solve();
}