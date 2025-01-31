#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7; 
struct node {
    int sum;
    node(){
        sum=0;
    }
};
node tree[4*200200];
int arr[200200];
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}

void build(int id,int l,int r){
    if(l==r){
        //leaf node
        tree[id].sum=0;
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
        tree[id].sum+=val;
        return;
    }
    int mid=(l+r)/2;

    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);

  tree[id]=merge(tree[2*id],tree[2*id+1]);

}
//here in updation we do the partial sum

node query(int id,int l,int r,int lq,int rq){
    if(lq>r||l>rq){
        return node();
    }
    if(lq<=l&&r<=rq){
        return tree[id];
    }
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
// here in query we make the prefix sum of the partial sum
void solve(){
    int n,q;
    cin>>n>>q;
  
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int a,b,u;
            cin>>a>>b>>u;
            a--,b--;
            update(1,0,n-1,a,u);
            update(1,0,n-1,b+1,-u);
        }else{
            int k;
            cin>>k;
            k--;
            node ans=query(1,0,n-1,0,k);
            cout<<ans.sum+arr[k]<<endl;

        }
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}