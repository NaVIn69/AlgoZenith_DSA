#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to find the float answer upto d decimal digit after the decimal , 
// according to the question we have the x*10^d is integer 
// previous (x-n)(y-n)=n^2 here we get the integer solution
// now (x*10^d-n*10^d)(y*10^d-n)=(n*10^d)^2 // (x`-n`)(y`-n`)=(n`)^2 => a.b=(n`)^2 here we a and b is integer and n` is also integer

void solve(){
    int n,d;
    cin>>n>>d;
    map<int,int>mpp;// here we store all the prime factor of n^2
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i){
                cnt++;
                n/=i;
            }
            if(cnt) mpp[i]+=2*cnt; 
            
        }
    }

}
signed main(){
    solve();
}