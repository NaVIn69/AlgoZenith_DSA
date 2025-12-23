#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int x=n;
    vector<int>prime_fact;
    for(int i=2;i*i<=x;i++){
         if(x%i==0){
           int prod=1;
            while(x%i==0){
               prod*=i;
            
                x/=i;
            }
            prime_fact.push_back(prod);
            
         }
    }
    if(x>1)prime_fact.push_back(x);
    // to minimize the  max(a,b) -> my l and r must be neares to the sqrt(a*b) -> at prefect sqrt we get the minimum maximum number
    int k=prime_fact.size();
    int minDiff=LLONG_MAX;
    int bestL=1;
    int bestR=n;


    // here we generate all the subset of the prime factor 2^log(n)
    for(int mask=0;mask<(1<<k);mask++){
           int l=1;
           for(int j=0;j<k;j++){
               if(mask&(1<<j)){
                 // here we are checking the jth bit is set or not
                 l=l*prime_fact[j];
               }
           }
           int r=n/l;
           if(l==r)continue;
           if(abs(l-r)<minDiff){
            minDiff=abs(l-r);
             bestL=l;
             bestR=r;
           }
    }
    cout<<bestL<<" "<<bestR<<endl;
    
}

signed main(){
    solve();
}