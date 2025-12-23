#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    // for printing the l and r ,
    int nz=0,no=0;
    for(int i=1;i<n;i++){
        if(str[i]=='0'&&str[i]==str[i-1]){
            nz++;
        }else if(str[i]=='1'&&str[i]==str[i-1]){
            no++;
        }
    }
    cout<<max(nz,no)<<endl;
    // brut force
    // int l=1,r=n-2;
    // while(l<=r){
    //     if(str[l]==str[l-1]){
    //         // here we found the continous  
    //     }else{
    //         l++;
    //     }
    //     if(str[r]==str[r+1]){
    //         r--;
    //     }
    //     // here 

    // }

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}