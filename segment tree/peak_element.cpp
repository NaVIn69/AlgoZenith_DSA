// here w ehave to count peak element in the array
// first and last index ko count nhi krna hai
// during merge condition we have to check only on the first last index and second ka first index pe
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[100100];
struct node{
    int cnt=0;
    int len;
    int last_second_last;
    int last_last;
    int first_first;
    int first_second;
    node(){
        len=0;
        cnt=0;
         last_second_last=1e9;
         last_last=0;
         first_first=0;
          first_second=1e9;  
    }
};
int namo=0;
node merge(node a,node b){
    node c;
    c.len=a.len+b.len;
    c.cnt=a.cnt+b.cnt;
    // cout<<namo<<" "<<c.cnt<<" ";
    if((a.len>=2&&b.len>=1)&&a.last_last>a.last_second_last&&a.last_last>b.first_first){
        c.cnt++;
    }
    if((a.len>=1&&b.len>=2)&&b.first_first>a.last_last&&b.first_first>b.first_second){
        c.cnt++;
    }
    //  if(a.len==3&&b.len==2){
       
    //  }
    if(a.len>=2&&b.len>=2){
    c.first_first=a.first_first;
    c.first_second=a.first_second;
    c.last_last=b.last_last;
    c.last_second_last=b.last_second_last;
    }else if(a.len==1&&b.len==1){
        c.first_first=a.first_first;
        c.first_second=b.first_first;
        c.last_last=b.first_first;
        c.last_second_last=a.first_first;
    }else if(a.len>=2&&b.len==1){
        c.first_first=a.first_first;
        c.first_second=a.first_second;
        c.last_last=b.first_first;
        c.last_second_last=a.last_last;
    }else if(a.len==1&&b.len>=2){
        c.first_first=a.first_first;
        c.first_second=b.first_first;
        c.last_last=b.last_last;
        c.last_second_last=b.last_second_last;
    }else if(a.len>=1&&b.len==0){
         if(a.len>=2){
            c.first_first=a.first_first;
            c.first_second=a.first_second;
            c.last_last=a.last_last;
            c.last_second_last=a.last_second_last;
         }else if(a.len>=1){
            c.first_first=a.first_first;
            c.last_last=a.last_last;
            c.last_second_last=1e9;
            c.first_second=1e9;
         }
    }else if(b.len>=1&&a.len==0){
          if(b.len>=2){
            c.first_first=b.first_first;
            c.first_second=b.first_second;
            c.last_last=b.last_last;
            c.last_second_last=b.last_second_last;
         }else if(b.len>=1){
            c.first_first=b.first_first;
            c.last_last=b.last_last;
            c.last_second_last=1e9;
            c.first_second=1e9;
         }
    }
    

    return c;
}
node tree[400400];
void build(int id,int l,int r){
    if(l==r){
        tree[id].len=1;
        tree[id].cnt=0;
        tree[id].first_first=arr[l]; 
        tree[id].last_last=arr[l];
        tree[id].first_second=1e9;
        tree[id].last_second_last=1e9;
       return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
      if(pos<l||pos>r){
        return;
      }
      if(l==r){
        tree[id].len=1;
        tree[id].cnt=0;
        tree[id].first_first=val;
        tree[id].last_last=val;
        tree[id].first_second=1e9;
        tree[id].last_second_last=1e9;
         return ;
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
    node ans= merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
    return ans;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    // for(int i=1;i<=13;i++){
    //     cout<<tree[i].cnt<<" ";
    // }
    int q;
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r).cnt<<endl;
        }else{
            int pos,val;
            cin>>pos>>val;
            update(1,0,n-1,pos,val);
        }
    }

}
signed main(){
    solve();
}