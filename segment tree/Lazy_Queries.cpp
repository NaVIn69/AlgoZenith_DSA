#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define maxn 100100
int mod=1e9+7;
//here lazy1 tells me about the set the value "v" in range [a...b]
//here lazy2 tells me about the inc the value  by "v" in range [a..b];
struct node{
    int sum,lazy1,lazy2;
    bool islazy1,islazy2;
    node(){
        sum=0;
        lazy1=0;
        lazy2=0;
        islazy1=false;
        islazy2=false;
    }

};
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;

}
node tree[4*maxn];
int arr[2*maxn];
void push(int id,int l,int r){
    if(tree[id].islazy1){
        tree[id].sum=tree[id].lazy1*(r-l+1);
    
    if(l!=r){
        tree[id<<1].lazy1=tree[id].lazy1;
        tree[id<<1].islazy1=true;
        tree[id<<1|1].lazy1=tree[id].lazy1;
        tree[id<<1|1].islazy1=true;
    }
    tree[id].islazy1=false;
    tree[id].lazy1=0;
    }
    // if(tree[id].islazy2){
    //     tree[id].sum=tree[id].sum+tree[id].lazy2*(r-l+1);
    //      if(l!=r){
    //     tree[id<<1].lazy2=tree[id].lazy1;
    //     tree[id<<1].islazy2=true;
    //     tree[id<<1|1].lazy2=tree[id].lazy1;
    //     tree[id<<1|1].islazy2=true;
    // }
    // tree[id].islazy2=false;
    // tree[id].lazy2=0;
    // }

}
void push2(int id,int l,int r){
     if(tree[id].islazy2){
        tree[id].sum=tree[id].sum+tree[id].lazy2*(r-l+1);
         if(l!=r){
        tree[id<<1].lazy2=tree[id].lazy2;
        tree[id<<1].islazy2=true;
        tree[id<<1|1].lazy2=tree[id].lazy2;
        tree[id<<1|1].islazy2=true;
    }
    tree[id].islazy2=false;
    tree[id].lazy2=0;
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
void update_set(int id,int l,int r,int lq,int rq,int v){
     push(id,l,r);
     if(lq>r||rq<l){
        return;
     }
     if(lq<=l&&r<=rq){
        tree[id].lazy1=v;
        tree[id].islazy1=true;
        push(id,l,r);
        return;
     }
     int mid=(l+r)>>1;
     update_set(id<<1,l,mid,lq,rq,v);
     update_set(id<<1+1,mid+1,r,lq,rq,v);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}
void update_inc(int id,int l,int r,int lq,int rq,int v){
    push2(id,l,r);
     if(lq>r||rq<l){
        return;
     }
     if(lq<=l&&r<=rq){
        tree[id].lazy2=v;
        tree[id].islazy2=true;
        push2(id,l,r);
        return;
     }
     int mid=(l+r)>>1;
     update_inc(id<<1,l,mid,lq,rq,v);
     update_inc(id<<1+1,mid+1,r,lq,rq,v);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);

}
//it is point update
// void update(int id,int l,int r,int pos,int val){
//       if(pos<l||pos>r){
//         return ;
//     }
//     if(l==r){
//         tree[id].sum+=val;
//         return;
//     }
//     int mid=(l+r)/2;

//     update(2*id,l,mid,pos,val);
//     update(2*id+1,mid+1,r,pos,val);

//   tree[id]=merge(tree[2*id],tree[2*id+1]);
// }
node query(int id,int l,int r,int lq,int rq){
     push(id,l,r);
     push2(id,l,r);
     if(lq>r||l>rq){
        return node();
     }
     if(lq<=l&&r<=rq){
        return tree[id];
     }
     int mid=(l+r)>>1;
     return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));

}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    // for(int i=1;i<4*n;i++){
    //     cout<<tree[i].sum<<" ";
    // }
    // cout<<"nav"<<endl;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
         int a,b,x;
         cin>>a>>b>>x;
         update_inc(1,1,n,a,b,x);

        }else if(x==2){
             int a,b,x;
         cin>>a>>b>>x;
         update_set(1,1,n,a,b,x);

        }else{
            int a,b;
            cin>>a>>b;
            node x=query(1,1,n,a,b);
            cout<<x.sum<<endl;

        }
    }
}
signed main(){
    solve();
}
