#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAXN 200200
int n,q;
int arr[MAXN];
struct node{
    int sum,maxi,lazy;
    node(){
        sum=0;
        maxi=0;
        lazy=0;
    }
};
node tree[4*MAXN];
node merge(node a,node b){
    node temp;
    temp.sum=a.sum+b.sum;
    temp.maxi=max(a.maxi,b.maxi);
    return temp;
}

void push(int id,int l,int r){
     if(tree[id].lazy){
        tree[id].sum=tree[id].lazy*(r-l+1);
        tree[id].maxi=tree[id].lazy;
        if(l!=r){
            tree[id<<1].lazy=tree[id].lazy;
            tree[id<<1|1].lazy=tree[id].lazy;
        }
        tree[id].lazy=0;
     }
}

// here we have to update the arr[l......r] to value v
// here 
void update(int id,int l,int r,int lq,int rq,int v){
     push(id,l,r);
     if(l>rq||r<rq){
        return;
     }
     if(lq<=l&&r<=rq){
        tree[id].lazy=v;
        push(id,l,r);
        return;
     }
     int mid=(l+r)>>1;
     update(id<<1,l,mid,lq,rq,v);
     update(id<<1|1,mid+1,r,lq,rq,v);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}

node query(int id,int l,int r,int lq,int rq){
    push(id,l,r);
    if(l>rq||r<rq){
        return node();
     }
     if(lq<=l&&r<=rq){
        
        return tree[id];
     }
     int mid=(l+r)>>1;
     return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}
void solve(){
    // cin>>n>>q;
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
   update(1,0,5,2,4,8);
   update(1,0,5,2,3,6);
   node ans=query(1,0,5,3,4);
   cout<<ans.sum<<" "<<ans.maxi<<endl;

 
}
signed main(){
    solve();
}
