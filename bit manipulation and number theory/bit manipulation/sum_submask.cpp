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
// find the sum of all submask
int total_sum=0;
for(int mask=0;mask<(1<<n);mask++){
    // generate all the submask
 
    for(int submask=mask;submask>0;submask=(submask-1)&mask){
        
        
        for(int i=0;i<n;i++){
            if(((submask>>i)>>1)&1){
                total_sum+=arr[i];
            }
        }
  

    }
   
}
cout<<total_sum<<endl;

}
signed main(){
    solve();
}