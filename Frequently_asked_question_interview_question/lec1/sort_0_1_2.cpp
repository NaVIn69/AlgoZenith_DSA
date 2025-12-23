#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


int n;
int arr[100100];

// 0- low-1 -> 0
// low - mid-1 -> 1 
// mid - high -1 -> unsorted
// high - n-1 -> 2

// 
void solve(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,mid=0,h=n-1;
    while(mid<=h){
        if(arr[mid]==0){
            swap(arr[l],arr[mid]);
            l++;
            mid++;
        }
        else if(arr[mid]==1)mid++;
        else{
         swap(arr[mid],arr[h]);
         h--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

// forward sorting 

   
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}