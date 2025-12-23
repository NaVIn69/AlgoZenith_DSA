#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int m=40;
int pow3[43],cost[40];
void precompute(){
     pow3[0]=1;
     for(int i=1;i<=43;i++){
         pow3[i]=pow3[i-1]*3LL;
     }
     // power of 3
     cost[0]=3;
     for(int i=1;i<=40;i++){
          cost[i]=pow3[i+1]+1LL*i*pow3[i-1];
     }
}
int sum_digits_base3(int  n) {
    int  s = 0;
    while (n > 0) { s += n % 3; n /= 3; }
    return s;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int  s3 = sum_digits_base3(n);
    if(k< s3){ 
        cout<<"-1"<< endl;
         return; 
    }   

    if(k >= n){
        cout<<3LL*n<<endl;
         return; 
        }

    int mg = ((n - k) + 1 ) / 2;   
   
    vector<int>cnt(m + 2, 0);
    cnt[0] = n;

    int ec = 0;
    for (int x = 0; x <= m && mg > 0; ++x) {
        if (cnt[x]<3) continue;
        int can=cnt[x] / 3;                
        int use=min(can, mg);    
        cnt[x]-=3*use;
        cnt[x + 1]+=use;
        ec+=use*pow3[x];               
        mg-= use;
    }

 
    if(mg>0){ 
        cout<<"-1"<<endl; 
        return; 
    }

    cout<<3LL*n + ec<< endl;

}

signed main(){
    int t=1;
    cin>>t;
    precompute();
    while(t--){
        solve();
    }
}