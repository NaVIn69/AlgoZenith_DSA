#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    int diffbit=0;
    for(int i=0;i<32;i++){
        if((ans>>i)&1){
            diffbit=i;
            break;
            // get the first one
        }
    }
    // here we have the ans elemet which is xor of two single  element
    // jha xor ka value 1 hai then we can divided the my array into two section based on that 
    vector<int>zero;
    vector<int>ones;
 
        for(int j=0;j<n;j++){

        if((arr[j]>>diffbit)&1){
           ones.push_back(arr[j]);
        }else{
            zero.push_back(arr[j]);
        }
    }
    int ans1=0;
    for(auto x:ones){
        ans1^=x;
    }
    ans1^=ans;
    int ans2=0;
    for(auto x:zero){
        ans2^=x;
    }
    ans2^=ans;
    cout<<ans1<<" "<<ans2<<endl;

}
signed main(){
    solve();

}