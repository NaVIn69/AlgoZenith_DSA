#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int lcm(int a,int b){
    int val=gcd(a,b);
    return (a*b)/val;
}
void solve(){
    int n;
    cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
  

   sort(arr.begin(),arr.end());
   int x=arr[0]*arr[n-1];
 
   vector<int>divisor;
   for(int i=2;i*1LL*i<=x;i++){
        if(x%i==0){
            divisor.push_back(i);
            if(i*i!=x){
                divisor.push_back(x/i);
            }
        }
   }
   
   

   sort(divisor.begin(),divisor.end());
   if(divisor==arr){
    cout<<x<<endl;
   }else{
    cout<<-1<<endl;
   }

}
signed main(){
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}