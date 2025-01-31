#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
node tree[400400];
void build(int id,int l,int r){
    if(l==r){
       tree[id].cnt=0;
       return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
//here inserting the element 
//means we are updating our segment tree by adding the element 
//adding the x to our segment tree
void update_add(int id,int l,int r,int x){
    if(x<l||x>r) return ;
    if(l==r){
        tree[id].cnt+=1;
        return ;
    }
    int mid=(l+r)/2;
   if(x<=mid){
    update_add(2*id,l,mid,x);
    }else {
    update_add(2*id+1,mid+1,r,x);
    }
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update_remove(int id,int l,int r,int x){
    if(x<l||x>r) return ;
    if(l==r){
       if(tree[id].cnt!=0){
        tree[id].cnt-=1;
       }
       return ;
    }
    int mid=(l+r)/2;
    if(x<=tree[2*id].cnt){
    update_remove(2*id,l,mid,x);
    }else{
    update_remove(2*id+1,mid+1,r,x);
    }
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
int query(int id,int l,int r,int k){
   
    if(l==r){
        return l;
    }
    int mid=(l+r)/2;
    int left=0;
    int right=0;
    if(k<=tree[2*id].cnt){
      return query(2*id,l,mid,k);
    }else{
       return query(2*id+1,mid+1,r,k-tree[2*id].cnt);
    }
}
void solve(){
    int q;
    cin>>q;
    build(1,0,4*q);
    while(q--){ 
        int ch;
        cin>>ch;
        //ch==1 insert the element in the data structure
        //ch==2 remove the element from data structrure
        //ch== 3 find thr kTh element in the data structure
        if(ch==1){
            int a;
            cin>>a;
          
            update_add(1,0,4*q,a);
            for(int i=1;i<=7;i++){
               cout<<tree[i].cnt<<" ";
            }
            cout<<"first"<<endl;;
        }else if(ch==2){
            int b;
            cin>>b;
            update_remove(1,0,4*q,b);
             for(int i=1;i<=7;i++){
               cout<<tree[i].cnt<<" ";
            }
            cout<<"second"<<endl;


        }else{
            int k;
            cin>>k;
            cout<<query(1,0,4*q,k)<<endl;
        }
    }

}
signed main(){
    solve();
}
