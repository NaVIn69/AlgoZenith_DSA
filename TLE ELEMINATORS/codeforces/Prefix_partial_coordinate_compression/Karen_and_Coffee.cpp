#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAX 200005
int n,k,q;
int arr[2*MAX];
int partial[2*MAX];
void solve(){
     cin>>n>>k>>q;
     int max_r=0;
     for(int i=0;i<n;i++){
          int l,r;
          cin>>l>>r;
          partial[l]+=1;
          partial[r+1]-=1;
          max_r=max(max_r,r);
     }
     for(int i=1;i<MAX;i++){
        partial[i]+=partial[i-1];
     }
     for(int i=0;i<MAX+1;i++){
         if(partial[i]>=k){
            partial[i]=1;
         }else{
            partial[i]=0;
         }
     }
     for(int i=1;i<MAX;i++){
        partial[i]+=partial[i-1];
     }
     while(q--){
        int l,r;
        cin>>l>>r;
    
        cout<<partial[r]-partial[l-1]<<endl;
     }

}
signed main(){
    solve();
}