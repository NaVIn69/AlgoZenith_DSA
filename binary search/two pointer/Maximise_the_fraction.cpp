#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
#define ld long double
int mod=1e9+7;
ld eps=1e-9;
int n,k;
int a[10010],b[10010];
bool check(ld mid){
    ld sum=0.0;
  //  int cnt=0;
  priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        sum=(a[i]-mid*b[i]);
        pq.push(sum);
        if(pq.size()>k){
            pq.pop();
        }
    }
    int sum1=0.0;
    while(!pq.empty()){
       sum1+=pq.top();
       pq.pop();
    }
    if(sum1>=0.0){
        return true;
    }
    return false;
        
     
    
   
}
void solve(){
   // int n,k;
    cin>>n>>k;
  //  int a[n],b[n];
    ld mini=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
       // mini=min(mini,b[i]);
    }
   ld ans=0.0;
   ld l=0.0;
   ld h=1e8;
   while(abs(h-l)>=eps){
    ld mid=(l+h)/2.0;
    if(check(mid)){
        ans=mid;
        l=mid;
    }else{
        h=mid;
    }

   }
  cout<<fixed<<setprecision(6)<<ans<<endl;
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