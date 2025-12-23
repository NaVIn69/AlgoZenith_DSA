#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
int a[1000000][2];
bool check(int mid){
    int number_of_people=1;
    for(int i=0;i<y;i++){
       number_of_people+=(abs(a[i][1]-a[i][0]))/mid;
    }
}
void solve(){
cin>>x>>y;
int max_difference=0;
for(int i=0;i<y;i++){
   cin>>a[i][0];
   cin>>a[i][1];
   max_difference=max(max_difference,abs(a[i][1]-a[i][0]));
}
int s=0;
int ans=max_difference;
int e=max_difference;
while(s<=e){
    int mid=s+(e-s)/2;
    if(check(mid)){
        ans=mid;
        s=mid+1;
    }else{
        e=mid-1;
    }
}
cout<<ans<<'\n';

}
signed main(){
int t;
cin>>t;
while(t--){
    solve();
}
}