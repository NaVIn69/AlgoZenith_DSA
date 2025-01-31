#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[200200];
struct node{
    int cnt;
    node(){
        cnt=0;
    }

};
node merge(node a,node b){
    node ans;
     ans.cnt=a.cnt+b.cnt;

}
node tree[400400];
bool iscorrect(int i){
    if(i<=0 ||i>=n-1) return false;
    return arr[i]>arr[i-1]&&arr[i]>arr[i+1];
}
void build(int id,int l,int r){
    if(l==r){
         tree[id].cnt=iscorrect(l)?1:0;
         return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);

}