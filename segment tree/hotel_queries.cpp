#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
    int maxi;

    node(){
        maxi=0;
     
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
        return ;
    }
    int mid=(l+r)/2;
    //left
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r){
        return ;
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

int query(int id,int l,int r,int val){
      if(tree[id].maxi<val){
        return 0;
      }
      if(l==r){
        // tree[id].maxi-=val;
       return l;
      }
      int mid=(l+r)/2;
      
      if(tree[id*2].maxi>=val){
         return  query(2*id,l,mid,val);
      }else{
        return query(2*id+1,mid+1,r,val);
      }
  
}
void solve(){
   int n,q;
   cin>>n>>q;

   for(int i=0;i<n;i++) cin>>arr[i];
   build(1,0,n-1);
   
   while(q--){
    int x;
    cin>>x;
    int ans=query(1,0,n-1,x);
    if(tree[1].maxi<x){
        cout<<"0"<<" ";
    }else{
        update(1,0,n-1,ans,x);
        cout<<ans+1<<" ";
    }

     
   }
   cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
}