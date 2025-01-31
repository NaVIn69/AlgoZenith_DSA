#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
    int maxi_sum;
    int start_index;
    int end_index;
    int total_sum;
    node(){
        maxi_sum=INT_MIN;
        start_index=0;
        end_index=0;
        total_sum=0;
    }
};
// node a me always left wala
// node b always right wala
node merge(node a,node b){
    node ans;
  //  ans.maxi_sum=max(a.maxi_sum,b.maxi_sum);
    if(a.end_index+1==b.start_index){
        if(a.maxi_sum*b.maxi_sum>=0){
           ans.maxi_sum=a.maxi_sum+b.maxi_sum;
           ans.start_index=a.start_index;
           ans.end_index=b.end_index; 
        }else{
            ans.maxi_sum=max(a.maxi_sum,b.maxi_sum);
            ans.start_index=min(a.start_index,b.start_index);
            ans.end_index=max(a.end_index,b.end_index);
        }
    }else{
        ans.maxi_sum=max(a.maxi_sum,b.maxi_sum);
           if(ans.maxi_sum==a.maxi_sum){
            ans.start_index=a.start_index;
            ans.end_index=a.end_index;
           }else{
            ans.start_index=b.start_index;
            ans.end_index=b.end_index;
           }
    }
    return ans;


}
int arr[200200];
node tree[4*200200];
void build(int id,int l,int r){
    if(l==r){
        tree[id].maxi_sum=arr[l];
        tree[id].start_index=l;
        tree[id].end_index=l;
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);

}
void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r){
        return;
    }
    if(l==r){
      
        tree[id].maxi_sum=val;
         tree[id].start_index=l;
        tree[id].end_index=l;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);

}
node query(int id,int l,int r,int lq,int rq){
       if(lq>r||rq<l){
        return node();
       }
       if(lq<=l&&r<=rq){
        return tree[id];
       }
       int mid=(l+r)/2;
       return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    // for(int i=0;i<4*n;i++){
    //     cout<<tree[i].maxi_sum<<" ";
    // }
    // cout<<endl;
    while(q--){
        int k,x;
        cin>>k>>x;
        k--;
        update(1,0,n-1,k,x);
      
    
        cout<<query(1,0,n-1,0,n-1).maxi_sum<<endl;

    }
    

}
signed main(){
    solve();
}