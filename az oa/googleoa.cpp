#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[100100];
struct node{
    vector<pair<int,int>>child;
    int sum;
    node(){
        sum=0;
        child.clear();
        //  vector<pair<int,int>>child;
    }
};
node tree[400400];
node merge(node a,node b){
    node ans;
    int a_sum=a.sum;
    vector<pair<int,int>>a_child=a.child;
    int b_sum=b.sum;
    vector<pair<int,int>>b_child=b.child;
    int sz_a=a_child.size();
    int sz_b=b_child.size();
    int sum=sz_b;
     vector<pair<int,int>>l;
    for(int i=0;i<sz_a;i++){
        a_child[i].second+=sum;
        l.push_back({a_child[i]});
        sum+=sz_b;
    }
    sum=sz_a*sz_b; 
    // reverse(b_child.begin(),b_child.end());
    for(int i=0;i<sz_b;i++){
        b_child[i].second+=sum;
        sum-=sz_a;
        l.push_back(b_child[i]);
    }
    int tot_a=0;
    for(int i=0;i<sz_a;i++){
        tot_a+=(a_child[i].first*a_child[i].second);
    }
    a.sum=tot_a;
    int tot_b=0;
    for(int i=0;i<sz_b;i++){
        tot_b+=(b_child[i].first*b_child[i].second);
    }
    b.sum=tot_b;
    ans.sum=tot_a+tot_b;
    ans.child=l;
    return ans;

}
void build(int id,int l,int r){
     if(l==r){
        tree[id].sum=arr[l];
        tree[id].child.push_back({arr[l],1});
        return ;
     }
     int mid=(l+r)/2;
     build(2*id,l,mid);
     build(2*id+1,mid+1,r);
     tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r){
        return ;
    }
    if(l==r){
        arr[pos]=val;
        tree[id].sum=val;
        tree[id].child.clear();
        tree[id].child.push_back({val,1});
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
    if(lq<=l&&r<=rq){
        return tree[id];
    }
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
  
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    build(1,0,n-1);
    // for(int i=1;i<=9;i++){
    //     cout<<tree[i].sum<<" ";
    // }
    cout<<endl;
    int q;
    cin>>q;
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
            // if(l==r){
            //     cout<<arr[l]<<endl;
            //     continue;
            // }
 
            cout<<query(1,0,n-1,l,r).sum<<endl;
        }

    }

}
signed main(){
    solve();
}