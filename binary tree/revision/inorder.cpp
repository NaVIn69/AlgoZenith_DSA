#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
    int val;
    node*left,*right;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

void inorder(node*root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void morris_inorder(node*curr){
    while(curr!=NULL){
        if(curr->left!=NULL){
            node*temp=curr->left;
            while(temp->right!=curr&&temp->right!=NULL){
                temp=temp->right;
            }
            if(temp->right==curr){
                // my connection is active , here we have to d
                temp->right=NULL; // here we are breaking the connection means we have been travelled all the nodes in left subtree
                // and also we have to travelled in the right direction
                cout<<curr->val<<" "; 
                curr=curr->right; // here we are going to right of tree because we have been traversed the left  
            }else{
                temp->right=curr;
                curr=curr->left;
            }
        }else{
            // here we print the data in inorder after thatw we 
            cout<<curr->val<<" ";
            curr=curr->right;
        }
    }
}
// root ->left->right
void morris_preorder(node*curr){
    while(curr!=NULL){
        if(curr->left!=NULL){
            node*temp=curr->left;
            while(temp->right!=curr&&temp->right!=NULL){
                temp=temp->right;

            }
            if(temp->right==curr){
                // means we have to deactivate the connection;
                temp->right=NULL;
                curr=curr->right;

            }else{
                // here first time we do the connection for that node
                cout<<curr->val<<" ";
                temp->right=curr;
                curr=curr->left;
            }
        }else{
            cout<<curr->val<<" ";
            curr=curr->right;
            // on leaf node

        }
    }
}

void solve(){

}
signed main(){
    solve();
}