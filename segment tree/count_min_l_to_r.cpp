#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here cnt= gives the mini element count in [l..r];
// mini =gives minimum value in [l....r];
struct node{
    int mini;
    int cnt;
    node(){
        mini=INT_MAX;
        cnt=0;
    }

};
node merge(node a,node b){
    node ans;
    ans.mini=min(a.mini,b.mini);
    if(ans.mini==a.mini){
    ans.cnt+=a.cnt;
    }
    if(ans.mini==b.mini){
        ans.cnt+=b.cnt;
    }
    return ans;

}
node tree[4*200200];
int arr[200200];
void build(int id,int l,int r){
    if(l==r){
        tree[id].mini=arr[l];
        tree[id].cnt=1;
        return;
    }
    int mid=(l+r)/2;
    //left child
    build(2*id,l,mid);
    //right child
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r){
        return;
    }
    if(l==r){
        tree[id].mini=val;
        return ;
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
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x,v;
            cin>>x>>v;
            update(1,0,n-1,x,v);
        }else{
            int l,r;
            cin>>l>>r;
            node ans=query(1,0,n-1,l,r);

            cout<<ans.mini<<" "<<ans.cnt<<endl;
        }
    }

}
signed main(){
    solve();
}