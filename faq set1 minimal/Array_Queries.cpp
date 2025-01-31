#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[1000100];
int n,k;
struct node{
    int val;
    // int index;
    node(){
        val=INT_MAX;
        // index=0;
    }
};
//each node has the maximum value of their range and and index of that value in the array
node merge(node a,node b){
    node ans;
    ans.val=max(a.val,b.val);
    // if(a.val==ans.val){
    //     ans.index=a.index;
    // }
    // if(b.val==ans.val){
    //     ans.index=min(b.index,ans.index);
    // }
    return ans;
}
node tree[4000400];
void build(int id,int l,int r){
    if(l>r){
        return;
    }
    if(l==r){
        tree[id].val=arr[l];
        // tree[id].index=l;
        return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update(int id,int l,int r,int pos,int value){
    if(pos<l||pos>r){
        return;
    }
    if(l==r){
        arr[pos]=value;
        tree[id].val=value;
        // tree[id].index=pos;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,value);
    update(2*id+1,mid+1,r,pos,value);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
int query1(int id,int l,int r,int k){
   if(l==r){
      if(tree[id].val>=k){
        return l;
      }
      return 1e9;
   }

   int mid=(l+r)/2;
   if(tree[2*id].val>=k){
    return query1(2*id,l,mid,k);
   }else{
    return query1(2*id+1,mid+1,r,k);
   }
  
}

void  solve(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x,y;
            cin>>x>>y;
            update(1,0,n-1,x-1,y);
        }else{
            int k;
            cin>>k;
            int ans=query1(1,0,n-1,k);
             if(ans==1e9){
                cout<<"-1"<<endl;
             }else{
                cout<<ans+1<<endl;
             }
        }
    }


}
signed main(){
    solve();
}