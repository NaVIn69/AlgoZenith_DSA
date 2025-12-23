#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

vector<int>divisor_all(int n){
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
         if(n%i==0){
             ans.push_back(i);
             if(i*i!=n){
            ans.push_back(n/i);
             }
         }
    }
    return ans;
}
vector<pair<int,int>>prime_factor(int n){
    vector<pair<int,int>>ans;
    for(int i=2;i*i<=n;i++){
         if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            ans.push_back({i,cnt});
         }
    }
    if(n>1){
        ans.push_back({n,1});
    }
    return ans;
}
bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
     if(n%i==0){
        return false;
     }
  }
  return true;
}
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

void solve(){
  int n;
  cin>>n;
 vector<pair<int,int>>ans=prime_factor(n);
  for(auto x:ans){
     cout<<x.first<<" "<<x.second<<endl;
  }


}
  
  

int main(){
  solve();
}