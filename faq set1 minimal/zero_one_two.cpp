#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int zeroptr=0;
    int twoptr=n-1;
    int ptr=0;
    while(ptr<=zeroptr){
        if(arr[ptr]==0){
            swap(arr[ptr],arr[zeroptr]);
            ptr++;
            zeroptr++;
        }else if(arr[ptr]==1){
            ptr++;
        }else{
            // arr[ptr]==2
            swap(arr[ptr],arr[twoptr]);
            twoptr--;
        }
    }

}
signed main(){
    solve();
}