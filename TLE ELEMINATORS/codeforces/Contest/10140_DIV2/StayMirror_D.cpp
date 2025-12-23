#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"

int n;

// here for every i,j we can check
void solve(){
 cin>>n;
 vector<int>arr(n,0);
 vector<int>brr(n,0);
 for(int i=0;i<n;i++){
    cin>>arr[i];
    brr[i]=arr[i];
 }
 long long ans=0;
 map<int,int>mpp; // for printing that array from where we get the minimum inversion count
 for(int i=1;i<=n;i++){
     // i is smallest number then we get the larger value on the both side
     int pos = 0;
     while (arr[pos] != i) pos++;
   
     // pos -> store the smallest number index 
     // in left (i<pos) and (arr[i]>arr[pos])->
     // we convert the 2*n-arr[i] -> this is greater than n 
     // inversion count of that number is (pos<j<n) (2*n-arr[i]>arr[j]) 
     // that is in the right side
    
     int mini=min(pos,((int)arr.size()-pos-1)); // min(l,r)
   //   cout<<pos<<" "<<n-pos-1<<" "<<mini<<endl;
     if(mini==pos){
        mpp[i]=i;
     }else{
        mpp[i]=2*n-i;
     }
     ans+=mini;
     arr.erase(arr.begin()+pos);
 }
 cout<<ans<<endl; // minimum inversion count;
//  for(int i=0;i<n;i++){
//     cout<<mpp[brr[i]]<<" ";// this is the array where we get the minimum inversion count
//  }

 
}
int main(){
    int t=1;
   //  cin>>t;
    while(t--){
        solve();
    }
}