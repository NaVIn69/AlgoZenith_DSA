#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];

struct node{
    int sum;
    node(){
        sum=0;
    }
};
node tree[400400];
node merge(node a,node b){
    node ans;
     ans.sum = a.sum+b.sum;
    return ans;
}
void build(int id,int l,int r){
    if(l==r){
        tree[id].sum=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
   tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
   if(pos<l||pos>r){
    return ;
   }
   if(l==r){
      arr[pos]=val;
      tree[id].sum=val;
      return ;
   }
   int mid=(l+r)/2;
   if(pos<=mid){
     update(2*id,l,mid,pos,val);
   }else{
    update(2*id+1,mid+1,r,pos,val);
   }
   tree[id]=merge(tree[2*id],tree[2*id+1]);
}
node query(int id,int l,int r,int lq,int rq){
    if(rq<l||lq>r){
        return node();
    }
    if(lq<=l&&rq>=r){
        return tree[id];
    }
    int mid=(l+r)/2;
 return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
void solve(){
    int q;
cin>>n>>q;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
build(1,0,n-1);



     while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int pos,val;
            cin>>pos>>val;
            update(1,0,n-1,pos,val);
        }else{
           int l,r;
           cin>>l>>r;
           int ans = query(1,0,n-1,l,r).sum;
           cout<<ans<<endl;

        }
     }
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}