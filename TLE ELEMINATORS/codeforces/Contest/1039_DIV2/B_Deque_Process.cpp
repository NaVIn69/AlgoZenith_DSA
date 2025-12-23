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
    int l=0,r=n-1;
    string str="";
    while(r-l>=4&&(l + 4 < n||r-4>=0)){
        if(l+4<n&&(arr[l]<arr[l+1])&&(arr[l+1]<arr[l+2])&&(arr[l+2]<arr[l+3])&&(arr[l+3]<arr[l+4])){
           // cout<<"left inc "<<endl;
            str+="L";
            l++;

        }else if(l+4<n&&(arr[l]>arr[l+1])&&(arr[l+1]>arr[l+2])&&(arr[l+2]>arr[l+3])&&(arr[l+3]>arr[l+4])){
            // cout<<"left dec"<<endl;
            str+="L";
            l++;
        }else if((r-4>=0&&arr[r]<arr[r-1])&&(arr[r-1]<arr[r-2])&&(arr[r-2]<arr[r-3])&&(arr[r-3]<arr[r-4])){
            // cout<<"right inc"<<endl;
            str+="R";
            r--;
        }else if((r-4>=0&&arr[r]>arr[r-1])&&(arr[r-1]>arr[r-2])&&(arr[r-2]>arr[r-3])&&(arr[r-3]>arr[r-4])){
            // cout<<"right dec"<<endl;
            str+="R";
            r--;
        }else{
            break;
        }
    }
    str+="LLLL";
    cout<<str<<endl;

}
signed main(){ 
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}