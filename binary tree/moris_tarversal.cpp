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

// here we are using the marking link , to make the connection  , 
// for any node we go node ke left  ke rightmost null ko connect kr denge node se
template<typename T>
void moris_traversal_IN(node<T>*root){
    while(root!=NULL){
        // here we go root ke left me
        node<T>*temp=root->left;
        if(temp!=NULL){
            // here we are checking the link and going to the rightmost node
            while(temp->right!=root&&temp->right!=NULL){
                temp=temp->right;
            }
            if(temp->right==root){ // connection is active
            // here we reach on that node , delete the connection , 
            temp->right=NULL;
            cout<<root->data<<" ";
            root=root->right;
            }else{
                // here we making the connection;
                temp->right=root;
                root=root->left;
            }

        }else{
            cout<<root->data<<" ";
            root=root->right;
        }
        
    }

}
template<typename T>
void moris_traversal_pre(node<T>*root){
    while(root!=NULL){
        // here we go root ke left me
        node<T>*temp=root->left;
        if(temp!=NULL){
            // here we are checking the link and going to the rightmost node
            while(temp->right!=root&&temp->right!=NULL){
                temp=temp->right;
            }
            if(temp->right==root){ // connection is active
            // here we reach on that node , delete the connection , 
            temp->right=NULL;
           // going to the right side of the current node (root) tree
            root=root->right;
            }else{
                // here we making the connection;
                cout<<root->data<<" ";
                // build the connection 
                temp->right=root;
                // going left of my current node (root)
                root=root->left;
            }

        }else{
            // here we get the leaf node 
            // and leaf node has the connection , previously we have been connected 
            // 
            cout<<root->data<<" ";
            // here we going to that node , where we have been connected
            // after that in next iteration , we incative that connection and , move to the 
            root=root->right;
        }
        
    }

}


void solve(){
    node<int>*root=takeInputlevelwise<int>();
     moris_traversal_IN(root);

}
signed main(){
    solve();
}
