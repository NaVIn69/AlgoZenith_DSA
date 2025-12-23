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
    // every element is occuring 3 time but one element is occuring 1 times we have find 1 element
    int ans=0;
    for(int i=31;i>=0;i--){
        int cnt=0; // here we count the ith bit of ever element 
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1){
                // checking ith bit (arr[j]&(1<<i))
                cnt++;
            }
        }
       // cout<<cnt<<endl;
        if(cnt%3){
            // menas that single element is contributing into the ith bit
            ans|=(1<<i); // here we are setting ith bit to the answer
        }
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}