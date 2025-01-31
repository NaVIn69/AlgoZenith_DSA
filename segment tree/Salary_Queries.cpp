#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
      int maxi;
      node(){
        maxi=0;
      }
};
node merge(node a,node b){
   node ans;
   ans.maxi=max(a.maxi,b.maxi);
   return ans;
}
node tree[4*200200];
int arr[200200];
void build(int id,int l,int r){
    if(l==r){
        tree[id].maxi=arr[l];
        return ;
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
        tree[id].maxi=val;
        return ;
    }
    int mid=(l+r)/2;
     update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);

}
int query(int id,int l,int r,int lq,int rq){
     if(lq>r||rq>l){
        return 0;
     }
      if(lq<=l&&r<=rq){
        return ;
    }
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='?'){
            int a,b;
            cin>>a>>b;
        }

    }
}