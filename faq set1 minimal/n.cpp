#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int solution(vector<int>&a,vector<int>&b,int x,int y){
    // x a to b
    // y  b to a
    int n=a.size();
    int tot_arr=0;
    int tot_brr=0;
    for(int i=0;i<n;i++){
    tot_arr+=a[i];
  }
  for(int i=0;i<n;i++) {
 
    tot_brr+=b[i];
  }

    int sz=a.size();
    int tot=0;
    tot=min(a[0],b[0]);
    bool flag;
    if(tot==a[0]) flag=true;
    else flag=false;
    for(int i=1;i<sz;i++){
        if(flag){
            int temp=min(a[i],x+b[i]);
            tot+=temp;
            if(temp==x+b[i]){
                flag=false;
            }
        }else{
            int temp=min(b[i],y+a[i]);
            if(temp==y+a[i]){
                flag=true;
            }
            tot+=temp;
            
        }
    }
    int ans1=tot;
    //let start ith car b
    tot=b[0];
    if(tot==a[0]) flag=true;
    else flag=false;
     for(int i=1;i<sz;i++){
        if(flag){
            int temp=min(a[i],x+b[i]);
            tot+=temp;
            if(temp==x+b[i]){
                flag=false;
            }
        }else{
            int temp=min(b[i],y+a[i]);
            if(temp==y+a[i]){
                flag=true;
            }
            tot+=temp;
            
        }
    }
    int ans2=tot;
    int ans3=min(tot_arr,tot_brr);
    int ans4=min(ans2,ans1);
    return min(ans4,ans3);
}
void solve(){
  cin>>n;
  vector<int>arr,brr;
  arr.resize(n,0);
  int tot_arr=0;
  brr.resize(n,0);
  int tot_brr=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    tot_arr+=arr[i];
  }
  for(int i=0;i<n;i++) {
    cin>>brr[i];
    tot_brr+=brr[i];
  }
  int x,y;
  cin>>x>>y;
//   int ans3=min(tot_brr,tot_arr);
  cout<<solution(arr,brr,x,y)<<endl;
  
  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
