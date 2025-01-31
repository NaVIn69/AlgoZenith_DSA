/*
here we have given the taller array and each element of taller array tells me about that how many element in front of that element is larger than the ith element of taller

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAXN 100100
int taller[100100];
int n;
struct node{
 int cnt;
 node(){
    cnt=0;
 }

};
node merge(node a,node b){
    node ans;
    ans.cnt=a.cnt+b.cnt;
    return ans;
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
   if(val<l||val>r){
    return;
   }
   if(l==r){
    tree[id].cnt=0;
    return;
   }
   int mid=(l+r)>>1;
   update_remove(id<<1,l,mid,val);
   update_remove(id<<1|1,mid+1,r,val);
   tree[id]=merge(tree[id<<1],tree[id<<1|1]);
}
int findkThsmallet(int id,int l,int r,int k){
    
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(k<=tree[id<<1].cnt){
    return findkThsmallet(id<<1,l,mid,k);
    }else{
      return  findkThsmallet(id<<1|1,mid+1,r,k-tree[id<<1].cnt);
    }
    
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>taller[i];
  }
  for(int i=1;i<=n;i++){
    update_insert(1,0,n+1,i);
  }
  int ans[n];
  for(int i=n-1;i>=0;i--){
     int k=(i+1)-taller[i];
     ans[i]=findkThsmallet(1,0,n+1,k);
     update_remove(1,0,n+1,ans[i]);
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  


}
signed main(){
   solve();
}