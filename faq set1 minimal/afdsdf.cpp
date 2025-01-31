#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100100];
bool check(int mid){
    if(mid==n-1) return 1;
    if(arr[mid]>arr[mid+1]) return 1;
    else return 0;
}
void solve(){
 
    cin>>n;
   
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int h=n-1;
    int ans=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            ans=mid;
            h=mid-1;
        
        }else{
            l=mid+1;
            
        }
    }

cout<<ans<<endl;
}
int main(){
    solve();
}