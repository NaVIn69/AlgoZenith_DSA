#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[200200];
struct node{

    int val;
    node(){
        val= -1;
    }
   
};
node merge(node a,node b){
    node ans;
    ans.val=a.val&b.val;
  
    return ans;
}
node t[400400];
void build(int id,int l,int r){
    if(r==l){
        t[id].val=arr[l];
       
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
   
   t[id]=merge(t[2*id],t[2*id+1]);
}
node query(int id,int l,int r,int lq,int rq){
      if(lq>r||rq<l){
        return  node();
      }
      if(l>=lq&&r<=rq){
        return t[id];
      }
      int mid=(l+r)/2;
      return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}


void solve(){
    int n;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     
        
        build(1 , 0 , n - 1 );
        int mini=1e9;
      for(int l=0;l<n;l++){
        int low=l;
        int high=n-1;
        while(low<=high){
            int r=(low+high)/2;
            node check=query(1,0,n-1,l,r);
            mini=min(mini,abs(k-check.val));
            if(check.val<k) high=r-1;
            else if(check.val>k) low=r+1;
            else{
                cout<<mini<<endl;
                return;
            }
        }
      }
      cout<<mini<<endl;
     
    
}
signed main(){
    solve();
}