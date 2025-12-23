#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i&1){
          sum+=a[i];
        }else{
           sum-=a[i];
        }
    }

    int fe=-1,le=-1,fo=-1,lo=-1;
    int best=0;
    for(int i=1;i<=n;i++){
        if(i&1){
            if(fo==-1){
                fo=i;
            }
            lo=i;
        }else{
            if(fe==-1){
                fe=i;
            }
            le=i;
        }
    }

    if(fo!=-1&&fo!=lo){
        best=max(best,lo-fo);
    }
    if(fe!=-1&&fe!=le){
        best=max(best, le-fe);
    }

     // different parit
     // o<e
     int minodd=LLONG_MAX;
     for(int i=1;i<=n;i++){
         if(i&1){
            minodd=min(minodd,i+2LL*a[i]);
         }else if(minodd!=LLONG_MAX){
            best=max(best,i+2LL*a[i]-minodd);
         }
     }

     int maxe=LLONG_MIN;
     for(int i=1;i<=n;i++){
         if((i&1)==0){
             maxe=max(maxe,2LL*a[i]-i);
         }else if(maxe!=LLONG_MIN){
            best=max(best,maxe+i-2LL*a[i]);
         }
     }

     cout<<sum+max(0LL,best)<<endl;

   


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}