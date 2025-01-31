#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// find sum of all xor of pair of array element
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<31;i++){
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0;i<n;i++){
            if((arr[i]>>i)&1){
                cnt[1]++;
            }else{
                cnt[0]++;
            }
        }
        sum+=(cnt[1]*cnt[0]*(1<<i));
    }
    cout<<sum<<endl;
}
signed main(){
    solve();
}