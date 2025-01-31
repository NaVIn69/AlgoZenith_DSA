#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
vector<int>arr,tree;
// tree[node] -> represent the sum of value [start,end]
void build(int node,int start,int end){
    if(start==end){
        // leaf node
        tree[node]=arr[start];
        return;
    }
    // left child
    int mid=(start+end)/2;
    build(2*node,start,mid);

    // right child
    build(2*node+1,mid+1,end);

    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(int node,int start,int end,int i,int x){
    if(start==end){
        //leaft node
        // start==i
        arr[i]=x;
        tree[node]=x;
        return;
    }
    int mid=(start+end)/2;
    if(i<=mid) update(2*node,start,mid,i,x);
    else update(2*node+1,mid+1,end,i,x);

    tree[node]=tree[2*node]+tree[2*node+1];
    //here updating the sum value
}

// tree[node]->represent the sum of [start,end]
int query(int node,int start,int end,int lq,int rq){
    if(start>=lq && end<=rq){
        // node is completely within the query range
        return tree[node];
    }
    if(start>rq || end<lq){
        // completely independent of query range
        return 0;
    }

    // partial intersectded
    int mid=(start+end)/2;
    return query(2*node,start,mid,lq,rq)+query(2*node+1,mid+1,end,lq,rq);
    
}
void solve(){
    int n,q;
    cin>>n>>q;
   
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    tree.resize(4*n);
    build(1,0,n-1);
    while(q--){
            int t;
            cin>>t;
        if(t==1){
            int i,x;
            cin>>i>>x;
           
           update(1,0,n-1,i-1,x);
        }else{
            int l,r;
            cin>>l>>r;
             
            cout<<query(1,0,n-1,l-1,r-1)<<endl;

        }
        
    }
    



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}