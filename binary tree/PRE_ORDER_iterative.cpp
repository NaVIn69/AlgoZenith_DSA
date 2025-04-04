#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
void preorder_iterative(node<int>*root){
    // here we are traversing iterative on the tree
    stack<node<int>*>st;
    st.push(root);
    while(!st.empty()){
        node<int>*front=st.top();
        st.pop();
        cout<<front->data<<" ";
        if(front->right){
            st.push(front->right);
        }
        if(front->left){
            st.push(front->left);
        }
    }
}
void inorder_iterative(node<int>*root){
    stack<node<int>*>st;
    // st.push(root);
    // when we get two time null means that node is leaf we have to move to the right of that root node

    node<int>*temp=root;
    while(true){
        if(temp){
            st.push(temp);
            temp=temp->left;
        }else{
            if(st.empty()) break;
            node<int>*front=st.top();
            st.pop();
            cout<<front->data<<" ";
            temp=temp->right;
            
        }

    }
}

// this function tells me about that we have been found the the val node or not
bool path(node<int>*root,node<int>*f,vector<int>&p){
  if(root==NULL) return false;
  p.push_back(root->data);
  if(f->data==root->data) return true;
  bool left=path(root->left,f,p);
//    if(!left) p.pop_back();
   bool right=path(root->right,f,p);
//    if(!right) p.pop_back();
   if(left || right){
    return true;
   }else{
      p.pop_back();
      return false;
   }

}
void solve(){
    node<int>*root=takeInputlevelwise<int>();
    // preorder_iterative(root);
    node<int>*newnode=new node<int>(4);
    vector<int>ans;
    path(root,newnode,ans);
    for(auto c:ans){
        cout<<c<<" ";
    }

}
int main(){
  solve();
}
