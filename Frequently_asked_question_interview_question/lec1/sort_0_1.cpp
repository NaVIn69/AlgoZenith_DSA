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
    int l=0,h=n-1;
    while(l<=h){
        if(arr[l]==0)l++;
        else if(arr[h]==1)h--;
        else{
            swap(arr[l],arr[h]);
            l++;
            h--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

// forward sorting 
void solve2(){
    cin>>n;
    int h=1e9;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            h=min(h,i);
        }
    }

    int l=0;
    while(l<=h&&l<n&&h<n){
        if(arr[l]==0)l++;
        else if(arr[h]==1)h++;
        else{
            swap(arr[l],arr[h]);
            l++,h++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve2();
    }
}