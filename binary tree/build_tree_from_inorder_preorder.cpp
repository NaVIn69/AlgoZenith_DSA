#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
map<int,int>mpp;
// map<int,int>mpp_post;
vector<char>pre,in,post;
// hasing methood
struct node{
  char val;
  node*left;
  node*right;
  node(int data){
    this->val=data;
    this->left=NULL;
    this->right=NULL;
 }

};

node*create_in_pre_to_binarytree(int lin,int rin,int lpre,int rpre){
    if(rin<lin) return NULL;
    int rootval=pre[lpre];
    int brpoints=mpp[rootval];
    node*root= new node(rootval);
    root->left=create_in_pre_to_binarytree(lin,brpoints-1, lpre+1,lpre+(brpoints-lin));
    root->right=create_in_pre_to_binarytree(brpoints+1,rin,lpre+(brpoints-lin)+1,rpre);
    return root;

}
node*create_in_post_to_binarytree(int lin,int rin,int lpos,int rpos){
    if(rin<lin) return NULL;
    if(rpos<lpos) return NULL;
    int rootval=post[rpos];
    int brpoints=mpp[rootval];
    node*root=new node(rootval);
    root->left=create_in_post_to_binarytree(lin,brpoints-1,lpos,lpos+(brpoints-lin)-1);
    root->right=create_in_post_to_binarytree(brpoints+1,rin,rpos-(rin-brpoints),rpos-1);

    return root;

}
void print(node*root){
      if(root==NULL) return ;
   cout<<root->val<<" : ";
   if(root->left!=NULL){
    cout<<" L "<<root->left->val<<", ";
   }
   if(root->right!=NULL){
    cout<<" R "<<root->right->val;
   }
   cout<<endl;
   print(root->left);
   print(root->right);
}


void postorderNotation(node*root){
    if(root==NULL) return ;
    postorderNotation(root->left);
    postorderNotation(root->right);
    cout<<root->val<<" ";
    // ans+=root->val;
}


void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        in.push_back(ch);
        mpp[ch]=i;
        // mpp_post[ch]=i;
    }
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        pre.push_back(ch);
    }
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        post.push_back(ch);
    }

    // node*root=create_in_pre_to_binarytree(0,n-1,0,n-1);
    node *root=create_in_post_to_binarytree(0,n-1,0,n-1);
    print(root);
    // postorderNotation(root);





}
signed main(){
    solve();
}