#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAXN 100100
int q,k;
struct node{
    int cnt;
    node(){
        cnt=0;
    }
};
node merge(node a,node b){
    node temp;
    temp.cnt=a.cnt+b.cnt;
    return temp;
}
node tree[4*MAXN];
void build(int id,int l,int r){
    if(l==r){
        tree[id].cnt=0;
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}
void update_insert(int id,int l,int r,int val){
    if(val<l||val>r) return ;

    if(l==r){
        tree[id].cnt++;
        return;
    }
    int mid=(l+r)>>1;
    update_insert(id<<1,l,mid,val);
    update_insert(id<<1|1,mid+1,r,val);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}
void update_remove(int id,int l,int r,int val){
    if(val<l||val>r) return ;

    if(l==r){
        tree[id].cnt--;
        return;
    }
    int mid=(l+r)>>1;
    update_remove(id<<1,l,mid,val);
    update_remove(id<<1|1,mid+1,r,val);
    tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}

int find_kth(int id,int l,int r,int k){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(k<=tree[id<<1].cnt){
      return  find_kth(id<<1,l,mid,k);
    }else{
       return find_kth(id<<1|1,mid+1,r,k-tree[id<<1].cnt);
    }
}

void solve(){
    cin>>q;
    while(q--){
       char ch;
       cin>>ch;
       if(ch=='+'){
        int val;
        cin>>val;
          update_insert(1,0,100,val);
       }else if(ch=='-'){
           int val;
           cin>>val;
           update_remove(1,0,100,val);
       }else{
             int k;
             cin>>k;
             cout<<find_kth(1,0,100,k)<<endl;
       }
       
    }


}
signed main(){
    solve();
}