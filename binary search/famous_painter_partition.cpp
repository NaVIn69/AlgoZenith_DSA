#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100000];
bool check(int x){
    int needed_painter=1;
        int time_left=x;
    for(int i=0;i<n;i++){
        if(time_left>=a[i]){
            time_left-=a[i];
        }else{
            needed_painter++;
            if(needed_painter>k){
                return 0;
            }
            time_left=x;
            if(time_left>=a[i]){
                time_left-=a[i];
            }else{
                return 0;
            }
        }
    }
    return 1;
}
void solve(){
    cin>>n>>k;
    int h=0;
    int l=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        h+=a[i];
        l=max(l,a[i]); 
    }
    int ans=0;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(check(mid)==1){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }


cout<<ans<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}