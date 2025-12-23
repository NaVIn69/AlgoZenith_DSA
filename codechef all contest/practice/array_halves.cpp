#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    n=2*n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int cnt=0;
   int check_val=n/2;
   int check_val_right=n/2;
   int check_val_left=check_val_right-1;
   int i=0;
   int j=n-1;
   while(i<=j){
     if(arr[i]<=check_val){
        i++;
        continue;
       
     }
     if(arr[j]>check_val){
        j--;
        continue;
     }
     if(arr[i]>check_val&&arr[j]<=check_val){
      
         cnt=cnt+(check_val_left-i)+(j-check_val_right)+1;
         i++;
         j--;
     }

   }
   cout<<cnt<<endl;
//    for(int i=0;i<n/2;i++){
//       if(arr[i]<=check_val){
//         continue;
//       }else{
//         cnt+=(2*(check_val-i)+1);
//       }
//    }
//    cout<<cnt<<endl;
    
    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}