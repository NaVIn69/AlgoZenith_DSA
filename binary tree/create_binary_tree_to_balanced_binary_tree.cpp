#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
template<typename T>
class node{
    public:
  T data;
  node*left;
  node*right;
  node(T data){
     this->data=data;
    this->left=nullptr;
     this->right=nullptr;
  }
//   ~Node(){
//     delete left;
//     delete right;
//   }

};
template<typename T>
node<T>*takeInputlevelwise(){
    T rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return nullptr;
    }
   node<T>*root=new node<T>(rootdata);
    queue<node<T>*>pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        node<T>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter leftchild of "<<front->data<<endl;
        T leftChild;
        cin>>leftChild;
        if(leftChild!=-1){
        node<T>*leftchild=new node<T>(leftChild);
        front->left=leftchild;
        pendingnodes.push(leftchild);
        }
        cout<<"Enter Rightchild of "<<front->data<<endl;
        T rightChild;
        cin>>rightChild;
          if(rightChild!=-1){
        node<T>*rightchild=new node<T>(rightChild);
        front->right=rightchild;
        pendingnodes.push(rightchild);
        }
        
    }
    return root;
}
vector<int>inorder;
void inorder_traversal(node<int>*root){
    if(root==NULL) return ;
    inorder_traversal(root->left);
    inorder.push_back(root->data);
    inorder_traversal(root->right);
}
node<int>*create_balanced_binary_tree(int st,int en,vector<int>&v){
  if(st>en) return NULL;
  int mid=(st+en)/2;
  // this is my root of the tree
  node<int>*root= new node<int>(v[mid]);
  root->left=create_balanced_binary_tree(st,mid-1,v);
  root->right=create_balanced_binary_tree(mid+1,en,v);
  return root;
}
template<typename T>
void print(node<T>*root){
    if(root==NULL) return;
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<" L "<<root->left->data<<" , ";
    }
    if(root->right!=NULL){
        cout<<" R "<<root->right->data<<" , ";
    }
    cout<<endl;
    print(root->left);
    print(root->right);

}


void solve(){
    // here we get the root of our binary tree , which we have taken
node<int>*root=takeInputlevelwise<int>();
// here we get all the inorder value of the 
inorder_traversal(root);
// here we can do  any type of traversal , bcz at th end we are sorting the vector
sort(inorder.begin(),inorder.end());
int n=inorder.size();
node<int>*bbst_root=create_balanced_binary_tree(0,n-1,inorder);
print(bbst_root);
}
signed main(){
    solve();
}