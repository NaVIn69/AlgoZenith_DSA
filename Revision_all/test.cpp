#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];

bool divisibleBypowerof2(int n,int k){
    int powerof2=1<<k;
    int num=powerof2-1; // this number have excatly k 1 bit from starting and which is divisible by 2^K number have the 0 on that position
    if(n&num==0); // n is divisible by 2^k

}
bool check_power_of2(int n){
    return n&(!(n&(n-1)));
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int j=31;j>=0;j--){
        int sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<j)){
               sum+=1;
            }
        }
        if(sum%3){
            ans=(ans|(1<<j));  
        }
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}