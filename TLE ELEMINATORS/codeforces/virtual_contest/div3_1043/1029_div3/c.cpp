#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    int freq[n+1]={0};
   int distnict[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
        if(freq[arr[i]]==1) distnict[i]=1;
         distnict[i]+=distnict[i-1];
    }
    // distnict[i] -> tell me count of distnict element till ith index
    // last segement maintaina all the distnict element of the array
    memset(freq, 0, sizeof(freq));
    int ans=0;
    int dis=0;
    int end=n;// end index  of that array where we are finding the distnict element
    for(int i=n;i>=1;i--){
          freq[arr[i]]++;
          if(freq[arr[i]]==1)dis++;
          if(dis==distnict[end]){
              // for this array ending at end we have been find the last segment where distnict is present
              ans++;
               for(int k=i;k<=end;k++){
                   freq[arr[k]]=0;// sare uss element ka frequency 0 kr diya 
               }
               end=i-1;
               dis=0; // here we start new array with new ending i-1 , we caculate now for this array 
          }
    }
    cout<<ans<<endl;
    
       
    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}