#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,a,b;
int arr[100];
void solve(){
  cin>>n>>a>>b;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  // a-> white b->black
  // 0-> white 1->black 2->didnt bought
  int l=0;
  int r=n-1;
  int ans=0;
  while(l<=r){
    if(l==r&&arr[r]==2){
        ans+=min(a,b);
        l++;
        r--;
        continue;
    }
     if(arr[r]==2){
        if(arr[l]==0){
            ans+=a;
        }else if(arr[l]==1){
          ans+=b;
        }else{
            ans+=(2*min(a,b));
        }
    }else if(arr[l]==2){
        if(arr[r]==0){
            ans+=a;
        }else if(arr[r]==1){
          ans+=b;
        }else{
            ans+=(2*min(a,b));
        }
    }
    else if(arr[l]!=arr[r]){
        cout<<"-1"<<endl;
        return ;
    }
    l++;
    r--;
  }
  cout<<ans<<endl;

}
signed main(){
    solve();
}