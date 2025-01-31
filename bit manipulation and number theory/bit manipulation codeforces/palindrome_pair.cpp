#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
  int n;
  cin>>n;
  int ans=0;
  map<int,int>mpp;
  for(int i=0; i<n;i++){
    string s;
    cin>>s;
    int mask=0;
    
    for(auto c:s){
        int val=c-'a';
        // here we are flipping the valth index bit via their occurance of character
        mask^=(1<<val);
    }
    // here mask is the bit representation of string according to their occrance 
    // even -0
    // odd=1
    ans+=mpp[mask];
    // here we convert the string in the binary representation
    // we have 26 possible binary string which is the palidrome
    /*
    {
    0 0 0 0 0 0 0 
    0 0 0 0 0 0 1
    0 0 0 0 0 1 0
    0 0 0 0 1 0 0
    .....
    these are the z
    these are the possible binary string which is palindrom
    x^Y=z
    we know the x is the mask of string and 
    we are trying to find the y by traversing the all possible 26 case
    means we are count j for every i 

    }
    
    */
    for(int flip=0;flip<26;flip++){
        
         mask^=(1<<flip);
         // mask is y
         ans+=mpp[mask];
         // add to the final answer
         mask^=(1<<flip);
         // beacome in the original conditiom
    }
    mpp[mask]++;



  }
  cout<<ans<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}