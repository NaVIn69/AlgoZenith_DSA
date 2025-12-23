#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,q;
string s;
int arr[1000005];
void solution(){
    for(int i=1;s[i]!='\0';i++){
        if(s[i]==s[i-1]){
            arr[i]=1;
        }
    }
    for(int i=1;i<n;i++){
        arr[i]=arr[i]+arr[i-1];
       // cout<<arr[i]<<" ";
    }
   // cout<<endl;
     
}
void solve(){
    cin>>n>>q;
    cin>>s;
    solution();
    while(q--){
        int l,r;
        cin>>l>>r;
         cout<<arr[r-1]-arr[l-1]<<endl;

    }

}
signed main(){
    solve();
}