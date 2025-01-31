#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7; 
struct node {
    int sum;
    int len;
  
    node(){
        sum=0;
        len=0;
      
    }
};
int arr[100100];
node merge(node a,node b){
  
 
}
node tree[4*200200];

void build(int id,int l,int r){
    if(l==r){
        //leaf node
        tree[id].sum=arr[l];
        tree[id].len=1; 
        return ;
    }
    int mid=(l+r)/2;
    //building the left child
    build(2*id,l,mid); 

    //building right child
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
    if(lq>r||l>rq){
        return node();
    }
    if(lq<=l&&rq>=r){
        return tree[id];
    }
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    

     while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int pos,val;
            cin>>pos>>val;
            update(1,0,n-1,pos,val);
        }else{
           int l,r;
           cin>>l>>r;
           int ans=query(1,0,n-1,l,r).sum*(r-l+1);
           cout<<ans<<endl;

        }
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   cin>>t;
    while(t--){
        solve();
    }
}