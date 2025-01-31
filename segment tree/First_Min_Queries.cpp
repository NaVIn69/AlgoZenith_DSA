#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
    int maxi;
    node(){
        maxi=INT_MIN;
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
      return;
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
        tree[id].maxi-=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
int query(int id,int l,int r,int x){
    if(tree[id].maxi<x){
         return 0;
    }
    if(l==r){
        return l;
    }
    int mid=(l+r)/2;
    if(tree[2*id].maxi>=x){
        return query(2*id,l,mid,x);
    }else{
        return query(2*id+1,mid+1,r,x);
    }
   
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int x;
        cin>>x;
        int index=query(1,1,n,x);
        if(index==0){
            cout<<index<<" ";
        }else{
            cout<<index<<" ";
            update(1,1,n,index,x);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
