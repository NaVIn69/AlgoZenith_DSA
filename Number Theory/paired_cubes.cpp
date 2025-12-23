#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int sp[1000100];

void smallestPrimefact(){
     for(int i=1;i<=1e6;i++){
         sp[i]=i;
     }
     
     for(int i=2;i<=1e6;i++){
          if(sp[i]==i){
              // all the multiple of of that sp[i] has sf as sp[i];
              for(int j=2*i;j<=1e6;j+=i){
                    if(sp[j]==j){
                        sp[j]=i;
                    }
              }
          }
     }

}

pair<int,int> primefact(int n){
    // here we get the {  }
    if(n==1){
        return {1,1};
    }
   
     map<int,int>mpp;
     int x=n;
     while(x>1){
         mpp[sp[x]]++;
         x/=sp[x];
     }
    
     
    int norm=1;
    int comp=1;
     for(auto&z:mpp){
        //   cout<<z.first<<" "<<z.second<<endl;
          int rem=z.second%3; // means that prime is z.second times then we need 3-z.second times to make cubic 
          if(rem==1){
            norm=norm*z.first;
            comp=comp*z.first*z.first;
          }else if(rem==2){
            norm=norm*z.first*z.first;
            comp=comp*z.first;
          }else{
             // zero time then what is missing and what is need 
          }
     }
     return {norm,comp};

}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
         cin>>arr[i];
    }
    smallestPrimefact();
    map<int,int>mpp;
    int ans=0;
    for(int i=0;i<n;i++){
        pair<int,int>temp=primefact(arr[i]);
        int norm = temp.first;
        int comp = temp.second;
        ans += mpp[comp];   // count how many earlier complement matches
        mpp[norm]++;  
    }
    cout<<ans<<endl;


}
signed main(){
    solve();
}