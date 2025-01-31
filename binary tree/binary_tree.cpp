#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreenode{
    public:
  T data;
  BinaryTreenode*left;
  BinaryTreenode*right;
  BinaryTreenode(T data){
     this->data=data;
    this->left=nullptr;
     this->right=nullptr;
  }
//   ~BinaryTreenode(){
//     delete left;
//     delete right;
//   }

};

template<typename T>
BinaryTreenode<T>*takeInput(){
     T rootdata;
     cout<<"Enter root data ";
     cin>>rootdata;
     if(rootdata==-1){
        return nullptr;
     }
     BinaryTreenode<T>*root= new BinaryTreenode<T>(rootdata);
     cout<<"Enter left child"<<root->data<<endl;
    BinaryTreenode<T>*leftChild=takeInput<T>();
    cout<<"Enter Right child"<<root->data<<endl;
    BinaryTreenode<T>*rightChild=takeInput<T>();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

template<typename T>
BinaryTreenode<T>*takeInputlevelwise(){
    T rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return nullptr;
    }
    BinaryTreenode<T>*root=new BinaryTreenode<T>(rootdata);
    queue<BinaryTreenode<T>*>pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        BinaryTreenode<T>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter leftchild of "<<front->data<<endl;
        T leftChild;
        cin>>leftChild;
        if(leftChild!=-1){
        BinaryTreenode<T>*leftchild=new BinaryTreenode<T>(leftChild);
        front->left=leftchild;
        pendingnodes.push(leftchild);
        }
        cout<<"Enter Rightchild of "<<front->data<<endl;
        T rightChild;
        cin>>rightChild;
          if(rightChild!=-1){
        BinaryTreenode<T>*rightchild=new BinaryTreenode<T>(rightChild);
        front->right=rightchild;
        pendingnodes.push(rightchild);
        }
        
    }
    return root;
}
template<typename T>
void printTree(BinaryTreenode<T>*root){
    if(root==nullptr) return;
    cout<<root->data<<" :";
    if(root->left!=nullptr){
        cout<<" L "<<root->left->data<<" ";
    }
     if(root->right!=nullptr){
        cout<<" R "<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

template<typename T>
void printTreelevelwise(BinaryTreenode<T>*root){
     
}

void solve(){
    BinaryTreenode<int>*root=takeInputlevelwise<int>();
    printTree(root);
}
int  main(){
  solve();
  return 0;
}