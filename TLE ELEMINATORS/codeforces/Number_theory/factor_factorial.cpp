#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int mod=1e9+7;
int legendry_exp(int n,int p){
     int ans=0;
     int prev=p;
     while((n/p)!=0){
        ans+=(n/p);
        p=p*prev;
     }
     return ans;
}
void solve(){
    int n;
    cin>>n;
  // here we legendry formula to caculate the power of p in n!
   // all prime number in n si
   int x=n;
   vector<int>p;
    vector<int>is_prime(x+1,1);
     for(int i=2;i<=x;i++){
           if(is_prime[i]){
            p.push_back(i);
               for(int j=i*i;j<=x;j+=i){
                  is_prime[j]=0;
               }
           } 
     }
    
     // for every prime number till n 
     int tot=1;
      for(int x:p){
       
        int cnt=legendry_exp(n,x);
        tot*=(cnt+1);
        if(tot>mod){
            tot%=mod;
        }
      }
      cout<<tot<<endl;

}
signed main(){
    solve();
}