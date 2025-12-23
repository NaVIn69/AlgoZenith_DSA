#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// int m=1e5+2;
int is_prime[1000100];
int spf[1000100];
void sieve(int maxi){
    for(int i=2;i<=maxi;i++){
        is_prime[i]=1;
    }
    for(int i=2;i<=maxi;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=maxi;j+=i){
                is_prime[j]=0;
            }
        }
    }
    for(int i=2;i<=maxi;i++){
        spf[i]=i;
    }
    for(int i=2;i<=maxi;i++){
         if(is_prime[i]){
            for(int j=2*i;j<=maxi;j+=i){
                spf[j]=i;
            }
         }
    }
}
vector<int>prime_fact(int n){
     vector<int>ans;
       while(n>1){
           ans.push_back(spf[n]);
           n/=spf[n];
       }
       return ans;
}

void solve(){
   int n,m;
   cin>>n>>m;
//    sieve(m+2);
   int arr[n];
   int maxi=0;
   set<int>st;
   for(int i=0;i<n;i++){
         cin>>arr[i];
         maxi=max(arr[i],maxi);
   }
   int na=max(maxi,m);
   sieve(na);
   for(int i=0;i<n;i++){
    if(arr[i]==1)continue;
    vector<int>ans=prime_fact(arr[i]);
    for(auto x:ans){
        st.insert(x);
    }

   }
   vector<int>ans(m+1,1);
   for(int x:st){
       for(int k=x;k<=m;k+=x){
           ans[k]=0;
       }
   }
   int cnt=0;
   vector<int>t;
     for(int i=1;i<=m;i++){
           if(ans[i]==1){
            t.push_back(i);
             cnt++;
           }
     }
     
     cout<<cnt<<endl;
     for(auto p:t){
         cout<<p<<endl;
     }
     cout<<endl; 

}
signed main(){
   
    solve();
}