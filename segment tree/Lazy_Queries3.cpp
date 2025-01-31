#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MXN 200200
int arr[MXN];
struct node{
    int sum;
    // here lazy1 for increasing each value by x
    int lazy1;
    // here lazy2 for setting each value by x
    int lazy2;
    node(){
        sum=0LL;
        lazy1=0LL;
        lazy2=0LL;
    }
    
};
node tree[4*MXN];
 node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;

}
void push(int id,int l,int r){

    if(tree[id].lazy2){
        tree[id].sum=tree[id].lazy2*(r-l+1);
        if(l!=r){
            tree[id<<1].lazy2=tree[id].lazy2;
            tree[id<<1].lazy1=0;
            tree[id<<1|1].lazy2=tree[id].lazy2;
            tree[id<<1|1].lazy1=0;
        }
        tree[id].lazy2=0;
    }
     if(tree[id].lazy1){
        tree[id].sum=tree[id].sum + tree[id].lazy1*(r-l+1);
        if(l!=r){
            tree[id<<1].lazy1+=tree[id].lazy1;
            tree[id<<1|1].lazy1+=tree[id].lazy1;
        }
        tree[id].lazy1=0;
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
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}
// here each value is going to increase by value x
void update1(int id,int l,int r,int lq,int rq,int val){
   push(id,l,r);
   if(lq>r||l>rq) return;
   if(lq<=l&&r<=rq){
      tree[id].lazy1=val;
      push(id,l,r);
      return;
   }

   int mid=(l+r)>>1;
   update1(id<<1,l,mid,lq,rq,val);
   update1(id<<1|1,mid+1,r,lq,rq,val);
   tree[id]=merge(tree[id<<1],tree[id<<1|1]);

}

// here each value is going to set by value x
void update2(int id,int l,int r,int lq,int rq,int val){
    push(id,l,r);
    if(lq>r||l>rq){
        return;
    }
    if(lq<=l&&r<=rq){
        tree[id].lazy2=val;
        push(id,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update2(id<<1,l,mid,lq,rq,val);
    update2(id<<1|1,mid+1,r,lq,rq,val);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}

// query find the sum between l to r
node query(int id,int l,int r,int lq,int rq){
   
     if(lq>r||l>rq){
        return node();
    }
     push(id,l,r);
    if(lq<=l&&r<=rq){
       return tree[id];
    }
    int mid=(l+r)>>1;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

void solve(){
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  build(1,0,n-1);
  while(q--){
    int ch;
    cin>>ch;
    if(ch==1){
        // increase every value by 1 in range [l......r]
       int l,r,x;
       cin>>l>>r>>x;
       l--,r--;
      update1(1,0,n-1,l,r,x);

    }else if(ch==2){
        // set every value by x in range [l........r]
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--;
        update2(1,0,n-1,l,r,x);

    }else{
   // here we have to find the sum in the range [l.......r]
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