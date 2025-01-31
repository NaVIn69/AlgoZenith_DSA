#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
struct node{
     int sum;
     node(){
        sum=0;
     }
};
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}
node tree[400400];
void build(int id,int l,int r){
    if(l==r){
        tree[id].sum=arr[l];
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
        arr[pos]=val;
        tree[id].sum=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
node query(int id,int l,int r,int lq,int rq){
    
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


}
signed main(){
    solve();
}