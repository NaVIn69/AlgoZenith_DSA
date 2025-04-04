#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we make the equation like xy-nx-ny+n^2=n^2 -> (x-n)(y-n)=n^2 // here we caluculate all the divisor of the n^2
// then after that 
vector<int>divisor(int n){
    vector<int>ans;
 for(int i=1;i*i<=n;i++){
    if(n%i==0){
        ans.push_back(i);
        if(i*i!=n){
            ans.push_back(n/i);
        }
    }
 }
 sort(ans.begin(),ans.end());
 return ans;
}
void solve(){
  int n;
  cin>>n;
  int k=n*n;
  vector<int>d=divisor(k);
  // here we traverse on the all the divisor and x=n+d1 , y= k/d1 +n;
  vector<pair<int,int>>all_sol;
  for(auto v:d){
     int x=v+n;
     int y=k/v+n;
     all_sol.push_back({x,y});
  }

}
signed main(){
    solve();
}