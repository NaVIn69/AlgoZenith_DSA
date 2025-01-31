
#include <bits/stdc++.h>
using namespace std;
int arr[100010];
struct node{
    int sum;
    int cnt;
    int ans;
    int ansr;
    int ansf;
    node(int s=0,int c=0,int a=0,int ar=0,int f=0){
     sum=s;
     cnt=c;
     ans=a;
     ansr=ar;
     ansf=f;
    }
};
node t[400040];
node merge(node a,node b){
   node c;
  c.sum=a.sum+b.sum;
  c.cnt=a.cnt+b.cnt;
  c.ans=a.ans+b.ans+a.cnt*b.sum;
  c.ansr=a.ansr+b.ansr+b.cnt*a.sum;
  c.ansf=a.ansf+b.ansf+b.cnt*a.ans+b.ansr*a.cnt;
  return c;
}
void build(int index,int l,int r){
    if(l==r){
        t[index].sum=arr[l];
        t[index].cnt=1;
        t[index].ans=arr[l];
        t[index].ansr=arr[l];
        t[index].ansf=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    t[index]=merge(t[index*2],t[index*2+1]);
}
void update(int index,int l,int r,int pos,int val){
    if(pos<l || pos>r)return;
    if(l==r){
        arr[l]=val;
        t[index].sum=arr[l];
        t[index].cnt=1;
        t[index].ans=arr[l];
        t[index].ansr=arr[l];
        t[index].ansf=arr[l];
        return;
    }
    int mid=(l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index]=merge(t[index*2],t[index*2+1]);
}
node query(int index,int l,int r,int lq,int rq){
    if(rq<l || r<lq)return node();
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid=(l+r)/2;
    return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}


int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a,b;
            cin>>a>>b;
            a--;
            update(1,0,n-1,a,b);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<query(1,0,n-1,l,r).ansf<<endl;
            // cout<<query(1,0,n-1,l,r).ansr<<endl;
            // cout<<query(1,0,n-1,l,r).sum<<endl;
            // cout<<query(1,0,n-1,l,r).ans<<endl;
            // cout<<query(1,0,n-1,l,r).cnt<<endl;
        }
    }
    return 0;
}