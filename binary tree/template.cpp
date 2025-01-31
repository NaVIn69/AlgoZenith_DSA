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
