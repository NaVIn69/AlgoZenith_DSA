#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAXN 200200
int arr[MAXN];
int n,q;
struct node{
    int sum;
    int lazy;
    node(){
        sum=0;
        lazy=0;
    }
};
node tree[4*MAXN];
node merge(node a,node b){
    node temp;
    temp.sum=a.sum+b.sum;
    return temp;
}
void push(int id,int l,int r){
   if(tree[id].lazy){
    tree[id].sum+=(r-l+1)*tree[id].lazy;
    if(l!=r){
        tree[id<<1].lazy+=tree[id].lazy;
        tree[id<<1|1].lazy+=tree[id].lazy;
    }
    tree[id].lazy=0;
   }
}
 void build(int id,int l,int r){
    if(l==r){
        tree[id].sum=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
 }
 void update(int id,int l,int r,int lq,int rq,int val){
    push(id,l,r);
    if(lq>r||l>rq){
        return;
    }
    if(l>=lq&&r<=rq){
        tree[id].lazy=val;
        push(id,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(id<<1,l,mid,lq,rq,val);
    update(id<<1|1,mid+1,r,lq,rq,val);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
 }
 node query(int id,int l,int r,int lq,int rq){
    if(lq>r||l>rq){
        return;
    }
    push(id,l,r);
    if(l>=lq&&r<=rq){
       return tree[id];
    }
    int mid=(l+r)>>1;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
 }

void solve(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   build(1,0,n-1);
   while(q--){
    int ch;
    cin>>ch;
    if(ch==1){
        int l,r;
        cin>>l>>r;
        l--,r--;
        update(1,0,n-1,l,r,1);
    }else if(ch==2){
         int l,r;
        cin>>l>>r;
        l--,r--;
        update(1,0,n-1,l,r,2);
    }else if(ch==3){
         int l,r;
        cin>>l>>r;
        l--,r--;
        update(1,0,n-1,l,r,3);
    }else{
         int l,r;
        cin>>l>>r;
        l--,r--;
        node ans=query(1,0,n-1,l,r);
        cout<<ans.sum<<endl;
    }

   }
   
}
signed main(){
    solve();
}