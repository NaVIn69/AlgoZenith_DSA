#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
  int a,b;
  cin>>a>>b;
  int n=b-a+1;
  int arr[n];
  for(int i=0;i<n;i++){
    arr[i]=a++;
  }
      int ans=0;
    for(int i=0;i<4;i++){
        int cnt_1=0;
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1){
                cnt_1++;
            }
        }
        // cout<<cnt_1<<endl;
        int tot=((cnt_1)*(cnt_1-1))/2;
        int val=(1LL<<i);
        cout<<tot*val<<endl;
        ans+=(tot*val);
        
    }
    cout<<ans<<endl;
}
signed main(){
    solve();
}