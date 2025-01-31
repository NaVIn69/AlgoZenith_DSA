#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define maxn 100100
struct node{
    int sum,maxi,lazy;
    bool islazy;
    node(){
        sum=0;
        maxi=INT_MIN;
        lazy=0;
        islazy=false;
    }

};
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    ans.maxi=max(a.maxi,b.maxi);
    return ans;
}
node tree[4*maxn];
void push(int id,int l,int r){
      if(tree[id].islazy){
        tree[id].sum=tree[id].lazy*(r-l+1);
        tree[id].maxi=tree[id].lazy;
        if(l!=r){
            tree[id<<1].lazy=tree[id].lazy;
            tree[id<<1].islazy=true;
            tree[id<<1|1].lazy=tree[id].lazy;
             tree[id<<1|1].islazy=true;
        }
        tree[id].islazy=false;
        tree[id].lazy=0;
      }
}
void update(int id,int l,int r,int lq,int rq,int v){
    //here we check that node is lazy or not 
    //if it is lazy then corrected it and make it unlazy
    push(id,l,r);
    if(lq>r||rq<l){
        return;
    }
    if(lq<=l&&r<=rq){
        tree[id].lazy=v;
       tree[id].islazy=true;
        push(id,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    update(id<<1,l,mid,lq,rq,v);
    update(id<<1|1,mid+1,r,lq,rq,v);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);

}
node query(int id,int l,int r,int lq,int rq){
      push(id,l,r);
    if(lq>r||rq<l){
        return node();
    }
    if(lq<=l&&r<=rq){
        return tree[id];
    }
    int mid=(l+r)>>1;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));

}
void solve(){
    update(1,0,9,0,5,3);
    update(1,0,9,6,9,4);
    node x=query(1,0,9,3,6);
    cout<<x.sum<<" "<<x.maxi<<endl;

}
signed main(){
    solve();
}
