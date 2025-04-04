// only square of prime is t prime number
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int lim=1e6+2;
int is_prime[1000003];
void solve(){
    // first find all the prime number from  1 to 1e6;
    for(int i=2;i<=lim;i++){
       is_prime[i]=1;
    }
    for(int i=2;i*i<=lim;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=lim;j+=i){
                is_prime[j]=0;
            }
        }
    }
    // here we have find all the prime number from 1 to 1e6
    // square of only prime number become my t prime number
    set<int>st;
    for(int i=2;i<=lim;i++){
        if(is_prime[i]){
            st.insert(i*i); // only square of prime number could be my answer 
        }
    }
  int q;
  cin>>q;
  while(q--){
    int x;
    cin>>x;
    if(st.find(x)!=st.end()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
  }

}
signed main(){
    solve();
}
