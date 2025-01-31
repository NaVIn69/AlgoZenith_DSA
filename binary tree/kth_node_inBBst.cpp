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
  T subtreesz;
  node(T data){
     this->data=data;
    this->left=nullptr;
     this->right=nullptr;
     this->subtreesz=1;
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
int subtreesize(node<int>*root){
    if(root==NULL) return 0;
    root->subtreesz= 1+subtreesize(root->left)+subtreesize(root->right);
    return root->subtreesz;

}
// here we have given the bbest root node
// and we have to find out the kTH element in the bbest tree

// here we can use the moris traversal , for decreasing the space complexity

template<typename T>
node<T>*kth_node_BBST(node<T>*root,int k){
    if(root==NULL) return NULL;

    int leftsize= root->left ? root->left->subtreesz : 0;
    // if we have leftsize is 0 means in left there is no any node
    // 
    if(k==leftsize+1){
        return root;
    }
    if(k<=root->left)
}
// here for finding the kth smallest node , we can do inorder traversal , then we get the sorted order 
template<typename T>
void print(node<T>*root){
    if(root==NULL) return ;
    cout<<" val "<<root->data<<" "<<root->subtreesz<<endl;
    print(root->left);
    print(root->right);

}


void solve(){
    node<int>*root=takeInputlevelwise<int>();
    subtreesize(root);
    print(root);
    int k=7;
    node<int>*ans=kth_node_BBST(root,6);
    cout<<ans->data<<endl;

}
signed main(){
    solve();
}
