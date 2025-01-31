// here node store the two value first is the number of even in start to end
// tree[node]-> represent number of even from start to end
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
vector<int>arr;
vector<pair<int,int>>tree;
// first odd
// second even

void build(int node,int start,int end){
    if(start==end){
        // leaf node
        if(arr[start]%2){
            tree[node].first+=1;
        }else{
            tree[node].second+=1;
        }
        return;
    }
    // left child
    int mid=(start+end)/2;
    build(2*node,start,mid);

    // right child
    build(2*node+1,mid+1,end);

    tree[node].first=tree[2*node].first+tree[2*node+1].first;
     tree[node].second=tree[2*node].second+tree[2*node+1].second;
}
void update(int node,int start,int end,int i,int x){
    if(start==end){
        //leaft node
        // start==i
        arr[i]=x;
        if(x%2){
            tree[node].first=1;
            tree[node].second=0;
            
        }else{
            tree[node].second=1;
            tree[node].first=0;
        }
        return;
    }
    int mid=(start+end)/2;
    if(i<=mid) update(2*node,start,mid,i,x);
    else update(2*node+1,mid+1,end,i,x);

    tree[node].first=tree[2*node].first+tree[2*node+1].first;
     tree[node].second=tree[2*node].second+tree[2*node+1].second;

    //here updating the sum value
}
// tree[node]->represent the sum of [start,end]
pair<int,int> query1(int node,int start,int end,int lq,int rq){
    if(start>=lq && end<=rq){
        // node is completely within the query range
        return {tree[node].first,tree[node].second};
    }
    if(start>rq || end<lq){
        // completely independent of query range
        return {0,0};
    }

    // partial intersectded
    
    int mid=(start+end)/2;
    pair<int,int>left=query1(2*node,start,mid,lq,rq);
    pair<int,int>right=query1(2*node+1,mid+1,end,lq,rq);
    return {left.first+right.first,left.second+right.second};
    
}
void solve(){
    int n,q;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }
    tree.resize(4*n,{0,0});
    build(1,0,n-1);
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch==0){
            int x,y;
            cin>>x>>y;
            update(1,0,n-1,x-1,y);
        }else if(ch==1){
               int l,r;
               cin>>l>>r;
               cout<<query1(1,0,n-1,l-1,r-1).second<<endl;
        }else{
             int l,r;
               cin>>l>>r;
               cout<<query1(1,0,n-1,l-1,r-1).first<<endl;
        }
    }
    

    




}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}