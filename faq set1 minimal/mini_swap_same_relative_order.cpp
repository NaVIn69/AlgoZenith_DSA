#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"nav"<<endl;
    //first zero pointer
    //first non zero pointer element
    // int fzero=0;
    // int fnonzero=0;
    // while(fnonzero<n&&fzero<n&&fnonzero>=fzero){
    //     if(arr[fzero]==0&&arr[fnonzero]!=0){
    //         swap(arr[fzero],arr[fnonzero]);
    //         fzero++;
    //         fnonzero++;
    //     }else if(arr[fnonzero]==0){
    //         fnonzero++;
    //     }else if(arr[fzero]!=0){
    //         fzero++;
    //     }

    //     }
    int zeroptr=0;
    for(int i=0;i<n;i++){
         if(arr[i]!=0){
            if(zeroptr!=i){
            swap(arr[zeroptr],arr[i]);
            zeroptr++;
            }
         }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
signed main(){
    solve();
}