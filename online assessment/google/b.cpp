#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
node tree[4*200200];
int arr[200200];
void build(int id,int l,int r){
   
    if(l==r){
        tree[id].sum=arr[l];
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
      tree[id].sum=val;
      return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

node query(int id,int l,int r,int lq,int rq){
       if(lq>=l&&rq<=r) return tree[id];
       int mid=(l+r)/2;
       if(mid>=r) return query(2*id,l,mid,lq,rq);
       if(mid<l) return query(2*id+1,mid+1,r,lq,rq);
       return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
       
}
void solve(){
   int n;
   cin>>n;
   pair<int,int>brr[n];
   for(int i=0;i<n;i++){
       cin>>brr[i].first;
       brr[i].second=i;
   }
   sort(brr,brr+n); 
   int idx[n];
   
   for(int i=0;i<n;i++){
     idx[i]=brr[i].second;
     arr[i]=brr[i].first;
   }

   int q;
   cin>>q;
   while(q--){
     int c,k;
     cin>>c>>k;
     int temp[k];
     for(int i=0;i<k;i++){
        cin>>temp[i];
        update(1,0,n-1,idx[temp[i]],0);
     }
     //here we do tha binary search on prices
   
    
   }
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