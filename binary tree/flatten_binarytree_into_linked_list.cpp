#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
   int val;
   node*left;
   node*right;
   node(int x){
    left=NULL;
    right=NULL;
    val=x;
   }
};

// here we are going to the most right and going to make flatten 

// right->left->root
void flatten_pre(node*root,node*&prev){
    if(root==NULL){
        return ;
    }
    flatten_pre(root->right,prev);
    flatten_pre(root->left,prev);
    // when we get the leaft node
    root->right=prev;
    root->left=NULL;
    prev=root;
}

// left->root->right



void solve(){

}
signed main(){
    solve();
}