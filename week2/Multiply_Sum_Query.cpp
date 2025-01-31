/*#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int n;
int a[1000000];

//gcd of a and b ;; gcd(gcd(a,b),c)-> a b,c ka gcd

int gcd(int a,int b){
  
 if(a==0){
   return b;

 }
 return gcd(b%a,a);
    
}

// a^p%mod 

int binpow(int a,int p,int mod){
if(p==0) return 1%mod;
if(p%2) return a*binpow(a,p-1,mod);
else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}
}
int pref2[1000000];
int pref1[1000000];

int sum_l_r2(int l,int r){
    if(l==0) return pref2[r];
    else{
        return pref2[r]-pref2[l-1];
    }
}
int sum_l_r1(int l,int r){
    if(l==0) return pref1[r];
    else return pref1[r]-pref1[l-1];
}


// solution
void solve(){
int q;
cin>>n>>q;

// input
for(int i=0;i<n;i++){
    cin>>a[i];
}


int q1=q;
// make prefix array
for(int i=0;i<n;i++){
   
    pref2[i]=a[i]*(i+1);
    pref1[i]=a[i];
    if(i) {
       pref1[i]+=pref1[i-1];
        pref2[i]=pref2[i]*(i+1)+pref2[i-1];
       pref1[i]=pref1[i];
        pref2[i]=pref2[i];
        }

}

for(int i=0;i<q;i++){
 int l,r;
cin>> l>> r;
int ans1=sum_l_r2(l,r);
int ans2=sum_l_r1(l,r);
int ans3=ans1-l*ans2;
cout<<(ans3%mod+mod)%mod<<endl;

}


}
signed main(){
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}*/

#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int sum_l_r1(const vector<int>& prefixSum,int l,int r){
    if(l==0) return prefixSum[r];
    else return prefixSum[r]-prefixSum[l-1];
}

int sum_l_r2(const vector<int>& prefixSum2,int l,int r){
    if(l==0) return prefixSum2[r];
    else return prefixSum2[r]-prefixSum2[l-1];
}

int solveQuery(const vector<int>& arr, const vector<int>& prefixSum,const vector<int>&prefixSum2 ,int l, int r) {
    int result = 0;
    int ans1=sum_l_r1(prefixSum,l,r)%MOD;
    int ans2=sum_l_r2(prefixSum2,l,r)%MOD;
    int ans3=ans2-l*ans1;
    return ans3%MOD;
}

signed main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // prefix sum
    vector<int> prefixSum(N);
    vector<int> prefixSum2(N);
    prefixSum[0] = arr[0];
    prefixSum2[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = (prefixSum[i - 1] + arr[i]) % MOD;
        prefixSum2[i]=(prefixSum2[i - 1] + arr[i]*(i+1))%MOD;
    }

    //  queries
    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        int result = solveQuery(arr, prefixSum, prefixSum2 , L-1, R-1);
        cout << (result%MOD+MOD)%MOD << endl;
    }


}
